import json
import time
from keystoneauth1 import identity
from keystoneauth1 import session
from neutronclient.neutron import client as client


username='daniao2017'
password='1314520liu'
project_name='cn-north-4'
project_domain_id='0629bb1a768026c42fffc00e25759f39'
user_domain_id='0616f01ac40010a50f83c00e74bc6e20'
auth_url='https://nlp-ext.cn-north-1.myhuaweicloud.com/v1'
auth = identity.Password(auth_url=auth_url,
                         username=username,
                         password=password,
                         project_name=project_name,
                         project_domain_id=project_domain_id,
                         user_domain_id=user_domain_id)
sess = session.Session(auth=auth)
neutron = client.Client(session=sess)



def createvpn(vpcid, local_cidr, peer_ip, peer_cidr):
    print "######## create vpn  ######"
    print "################### step 1 vpn service ############"
    
    vpnservice = {
        "vpnservice": {        
            "router_id": vpcid,
            "name": "myservice",
            "admin_state_up": "true"
        }
    }
    
    ret = neutron.create_vpnservice(vpnservice)
    
    vpnserviceid = ret['vpnservice']['id']
    print "vpnserviceid = "+vpnserviceid
    
    print "public_ip = "+ret['vpnservice']['external_v4_ip']
    
    
    
    print "################### step 2 ike policy ############"
    
    ikepolicy = {
        "ikepolicy": {
            "phase1_negotiation_mode": "main",
            "auth_algorithm": "sha1",
            "encryption_algorithm": "aes-128",
            "pfs": "group5",
            "lifetime": {
                "units": "seconds",
                "value": 86400
            },
            "ike_version": "v1",
            "name": "ikepolicy1"
        }
    }
    
    ret = neutron.create_ikepolicy(ikepolicy)
    
    ikepolicyid = ret['ikepolicy']['id']
    print "ikepolicyid = "+ikepolicyid
    
    
    
    print "################### step 3 ipsec policy ############"
    
    ipsecpolicy = {
        "ipsecpolicy": {
            "name": "ipsecpolicy1",
            "transform_protocol": "esp",
            "auth_algorithm": "sha1",
            "encapsulation_mode": "tunnel",
            "encryption_algorithm": "aes-128",
            "pfs": "group5",
            "lifetime": {
                "units": "seconds",
                "value": 3600
            }
        }
    }
    
    ret = neutron.create_ipsecpolicy(ipsecpolicy)
    
    ipsecpolicyid = ret['ipsecpolicy']['id']
    print "ipsecpolicyid = "+ipsecpolicyid
    
    
    print "################### step 4 local and remote endpoints ############"
    
    localendpointgroup = {
        "endpoint_group": {
            "endpoints": local_cidr,
            "type": "cidr",
            "name": "my-localendpoints"
        }
    }
    
    ret = neutron.create_endpoint_group(localendpointgroup)
    
    localepgroupid = ret['endpoint_group']['id']
    print "localepgroupid = "+localepgroupid
    
    #### remote endpoint group 
    remoteendpointgroup = {
        "endpoint_group": {
            "endpoints": peer_cidr,
            "type": "cidr",
            "name": "remote-localendpoints"
        }
    }
    
    ret = neutron.create_endpoint_group(remoteendpointgroup)
    
    remoteepgroupid = ret['endpoint_group']['id']
    print "remoteepgroupid = "+remoteepgroupid
    
    
    
    print "################### step 5 ipsec connection ############"
    
    ipsecconnection = {
        "ipsec_site_connection": {
            "psk": "secret",
            "initiator": "bi-directional",
            "ipsecpolicy_id": ipsecpolicyid,
            "admin_state_up": "true",
            "mtu": "1500",
            "peer_ep_group_id": remoteepgroupid,
            "ikepolicy_id": ikepolicyid,
            "vpnservice_id": vpnserviceid,
            "local_ep_group_id": localepgroupid,
            "peer_address": peer_ip,
            "peer_id": peer_ip,
            "name": "vpnconnection1"
        }
    }
    
    ret = neutron.create_ipsec_site_connection(ipsecconnection)
    
    ipsec_connection_id = ret['ipsec_site_connection']['id']
    print "ipsec_connection_id = "+ipsec_connection_id


    
def update_peer_ip(masterip, backupip):
    print "######## update peer ip ######"
    newcontent = {
        "ipsec_site_connection": {
            "peer_address": backupip,
            "peer_id":backupip
        }
    }
    
    connections = neutron.list_ipsec_site_connections()
  
    entrys = connections['ipsec_site_connections']
    for entry in entrys:
        if (masterip == entry["peer_address"]):
            id = entry["id"]
            neutron.update_ipsec_site_connection(id, newcontent)
            time.sleep(3)           

def show_all_connections():
    print "######## show all ipsec connections "
    connections = neutron.list_ipsec_site_connections()
    entrys = connections['ipsec_site_connections']
    for entry in entrys:
        print entry  

def main():
    
    createvpn(vpcid="xxx", 
              local_cidr=["10.2.0.0/24","10.3.0.0/24"], 
              peer_ip="172.24.4.233", 
              peer_cidr=["20.2.0.0/24"])
              
    show_all_connections()
    #update_peer_ip(masterip="172.24.4.233", backupip="101.0.0.1")
    
  
if __name__ == '__main__':
    main()