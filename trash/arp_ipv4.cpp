#define LOG_MODULE PacketLogModuleIpv4Layer

#include "Ipv4Layer.h"
#include "PayloadLayer.h"
#include "IpUtils.h"
#include "Logger.h"
#include <string.h>
#include <sstream>
#include <endian.h>

namespace pcpp{
	uint8_t Ipv4Layer::getVersion(){
		uint8_t version;
		ipv4hdr* hdrdata = (ipv4hdr*)m_Data;
		version = (hdrdata->version);
		return version;
	}

	void Ipv4Layer::setVersion(uint8_t value){
		ipv4hdr* hdrdata = (ipv4hdr*)m_Data;
	}
	uint8_t Ipv4Layer::getIhl(){
		uint8_t ihl;
		ipv4hdr* hdrdata = (ipv4hdr*)m_Data;
		ihl = (hdrdata->ihl);
		return ihl;
	}

	void Ipv4Layer::setIhl(uint8_t value){
		ipv4hdr* hdrdata = (ipv4hdr*)m_Data;
	}
	uint8_t Ipv4Layer::getDiffserv(){
		uint8_t diffserv;
		ipv4hdr* hdrdata = (ipv4hdr*)m_Data;
		diffserv = (hdrdata->diffserv);
		return diffserv;
	}

	void Ipv4Layer::setDiffserv(uint8_t value){
		ipv4hdr* hdrdata = (ipv4hdr*)m_Data;
	}
	uint16_t Ipv4Layer::getTotallen(){
		uint16_t totalLen;
		ipv4hdr* hdrdata = (ipv4hdr*)m_Data;
		totalLen = htons(hdrdata->totalLen);
		return totalLen;
	}

	void Ipv4Layer::setTotallen(uint16_t value){
		ipv4hdr* hdrdata = (ipv4hdr*)m_Data;
	}
	uint16_t Ipv4Layer::getIdentification(){
		uint16_t identification;
		ipv4hdr* hdrdata = (ipv4hdr*)m_Data;
		identification = htons(hdrdata->identification);
		return identification;
	}

	void Ipv4Layer::setIdentification(uint16_t value){
		ipv4hdr* hdrdata = (ipv4hdr*)m_Data;
	}
	uint8_t Ipv4Layer::getFlags(){
		uint8_t flags;
		ipv4hdr* hdrdata = (ipv4hdr*)m_Data;
		flags = (hdrdata->flags);
		return flags;
	}

	void Ipv4Layer::setFlags(uint8_t value){
		ipv4hdr* hdrdata = (ipv4hdr*)m_Data;
	}
	uint16_t Ipv4Layer::getFragoffset(){
		uint16_t fragOffset;
		ipv4hdr* hdrdata = (ipv4hdr*)m_Data;
		fragOffset = htons(hdrdata->fragOffset);
		return fragOffset;
	}

	void Ipv4Layer::setFragoffset(uint16_t value){
		ipv4hdr* hdrdata = (ipv4hdr*)m_Data;
	}
	uint8_t Ipv4Layer::getTtl(){
		uint8_t ttl;
		ipv4hdr* hdrdata = (ipv4hdr*)m_Data;
		ttl = (hdrdata->ttl);
		return ttl;
	}

	void Ipv4Layer::setTtl(uint8_t value){
		ipv4hdr* hdrdata = (ipv4hdr*)m_Data;
	}
	uint8_t Ipv4Layer::getProtocol(){
		uint8_t protocol;
		ipv4hdr* hdrdata = (ipv4hdr*)m_Data;
		protocol = (hdrdata->protocol);
		return protocol;
	}

	void Ipv4Layer::setProtocol(uint8_t value){
		ipv4hdr* hdrdata = (ipv4hdr*)m_Data;
	}
	uint16_t Ipv4Layer::getHdrchecksum(){
		uint16_t hdrChecksum;
		ipv4hdr* hdrdata = (ipv4hdr*)m_Data;
		hdrChecksum = htons(hdrdata->hdrChecksum);
		return hdrChecksum;
	}

	void Ipv4Layer::setHdrchecksum(uint16_t value){
		ipv4hdr* hdrdata = (ipv4hdr*)m_Data;
	}
	uint32_t Ipv4Layer::getSrcaddr(){
		uint32_t srcAddr;
		ipv4hdr* hdrdata = (ipv4hdr*)m_Data;
		srcAddr = htonl(hdrdata->srcAddr);
		return srcAddr;
	}

	void Ipv4Layer::setSrcaddr(uint32_t value){
		ipv4hdr* hdrdata = (ipv4hdr*)m_Data;
	}
	uint32_t Ipv4Layer::getDstaddr(){
		uint32_t dstAddr;
		ipv4hdr* hdrdata = (ipv4hdr*)m_Data;
		dstAddr = htonl(hdrdata->dstAddr);
		return dstAddr;
	}

	void Ipv4Layer::setDstaddr(uint32_t value){
		ipv4hdr* hdrdata = (ipv4hdr*)m_Data;
	}
	void Ipv4Layer::parseNextLayer(){
		if (m_DataLen <= sizeof(ipv4hdr))
			return;

		ipv4hdr* hdrdata = getIpv4Header();
		uint8_t protocol = (hdrdata->protocol);
		if (protocol == 0x01)
			m_NextLayer = new IcmpLayer(m_Data+sizeof(ipv4hdr), m_DataLen - sizeof(ipv4hdr), this, m_Packet);
		else
			m_NextLayer = new PayloadLayer(m_Data + sizeof(ipv4hdr), m_DataLen - sizeof(ipv4hdr), this, m_Packet);
	}

	std::string Ipv4Layer::toString(){}

}