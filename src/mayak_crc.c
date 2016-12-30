#include "checksum.h"

uint16_t crc_3309(uint16_t crc, uint8_t *pData, uint32_t size){
	uint8_t d;

	while (size--) {
		d = *pData ^ (crc & 0xFF);
		d ^= d << 4;
		crc = (d << 3) ^ (d << 8) ^ (crc >> 8) ^ (d >> 4);

		pData++;
	}

	return crc;
}


#if 0
uint16_t crc16_ccitt(unsigned char *data_p, uint32_t length)
	/* Calculate and Store Rom CRC */
	for (CRCh = CRCl = 0, Addr = BootOffset; Addr<(RomSize - 4); Addr++)
	{

		/*b = a = Rom[Addr] ^ CRCl;
		a <<= 4; b = a = b ^ a;
		a >>= 4; CRCl = a = a ^ CRCh;
		a = b << 3; CRCl ^= a;
		a = b >> 5; CRCh = a ^ b;
		*/
		d = Rom[Addr] ^ (CRC & 0xFF); // Compute combined value.
		d ^= d << 4;
		CRC = (d << 3) ^ (d << 8) ^ (CRC >> 8) ^ (d >> 4);
	}
	Rom[Addr++] = (CRC & 0xFF) ^ 0xFF;
	Rom[Addr] = (CRC >> 8) ^ 0xFF;
}
#endif