-- protocol naming
p4_udp = Proto('p4_udp','P4_UDPProtocol')

-- protocol fields
local p4_udp_srcPort = ProtoField.string('p4_udp.srcPort','srcPort')
local p4_udp_dstPort = ProtoField.string('p4_udp.dstPort','dstPort')
local p4_udp_length_ = ProtoField.string('p4_udp.length_','length_')
local p4_udp_checksum = ProtoField.string('p4_udp.checksum','checksum')
p4_udp.fields = {p4_udp_srcPort, p4_udp_dstPort, p4_udp_length_, p4_udp_checksum}


-- protocol dissector function
function p4_udp.dissector(buffer,pinfo,tree)
    pinfo.cols.protocol = 'P4_UDP'
    local subtree = tree:add(p4_udp,buffer(),'P4_UDP Protocol Data')
        subtree:add(p4_udp_srcPort,tostring(buffer(0,2):bitfield(0,16)))
        subtree:add(p4_udp_dstPort,tostring(buffer(2,2):bitfield(0,16)))
        subtree:add(p4_udp_length_,tostring(buffer(4,2):bitfield(0,16)))
        subtree:add(p4_udp_checksum,tostring(buffer(6,2):bitfield(0,16)))

end

print( (require 'debug').getinfo(1).source )

-- creation of table for next layer(if required)

-- No table required

-- protocol registration
my_table = DissectorTable.get('p4_ipv4.protocol')
my_table:add(0x11,p4_udp)
