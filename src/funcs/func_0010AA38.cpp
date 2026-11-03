struct Region_0010AA38 {
    char pad[0xC];
    char m_name[1];
};

struct Mgr_0010AA38 {
    const char* GetHeapName(unsigned int crc);
};

extern "C" Region_0010AA38* func_0010BC50(Mgr_0010AA38* self, unsigned int crc);

extern char D_0035B090[];
extern char D_0035B0A0[];
extern char D_0035B0B0[];
extern char D_0035B0C0[];
extern char D_0035B0D0[];
extern char D_0035B0E0[];
extern char D_0035B0F8[];
extern char D_0035B110[];
extern char D_0035B120[];
extern char D_00388A78[];
extern char D_00388A80[];
extern char D_00388A88[];
extern char D_00388A90[];
extern char D_0035B130[];
extern char D_0035B140[];
extern char D_0035B150[];
extern char D_0035B160[];
extern char D_0035B170[];
extern char D_0035B180[];
extern char D_0035B190[];
extern char D_0035B1A8[];
extern char D_0035B1B8[];

const char* Mgr_0010AA38::GetHeapName(unsigned int crc)
{
    Region_0010AA38* r = func_0010BC50(this, crc);
    if (r) {
        return r->m_name;
    }
    switch (crc) {
    case 0x0C7800B0: return D_0035B090;
    case 0x8FDB68AF: return D_0035B0A0;
    case 0x62F3A0F3: return D_0035B0B0;
    case 0xE3551D2E: return D_0035B0C0;
    case 0x96D29D93: return D_0035B0D0;
    case 0xFCD5166B: return D_0035B0E0;
    case 0x90020867: return D_0035B0F8;
    case 0x0FA33D9B: return D_0035B110;
    case 0x70CB0238: return D_0035B120;
    case 0xC3909393: return D_00388A78;
    case 0xB497A305: return D_00388A80;
    case 0x2D9EF2BF: return D_00388A88;
    case 0x5A99C229: return D_00388A90;
    case 0x572A9F4C: return D_0035B130;
    case 0x202DAFDA: return D_0035B140;
    case 0xB924FE60: return D_0035B150;
    case 0xCE23CEF6: return D_0035B160;
    case 0x08682D24: return D_0035B170;
    case 0x17ECB880: return D_0035B180;
    case 0x7ED56B49: return D_0035B190;
    case 0x25D71469: return D_0035B1A8;
    }
    return D_0035B1B8;
}
