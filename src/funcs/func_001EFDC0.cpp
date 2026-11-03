struct Obj_001EFDC0;

extern Obj_001EFDC0* D_0038E7D4;
extern "C" void func_001EEF80(Obj_001EFDC0* self);
extern "C" void func_001EF5E0(Obj_001EFDC0* self);
extern "C" void func_001EF6E0(Obj_001EFDC0* self);
extern "C" void func_001EF778(Obj_001EFDC0* self);
extern "C" void func_001EF818(Obj_001EFDC0* self);
extern "C" void func_001EF788(Obj_001EFDC0* self);
extern "C" void func_001EF9C0(Obj_001EFDC0* self);
extern "C" void func_001EFB00(Obj_001EFDC0* self);
extern "C" void func_001EFBE0(Obj_001EFDC0* self);
extern "C" int func_001EFCA8(Obj_001EFDC0* self);
extern "C" void func_001EF228(Obj_001EFDC0* self);
extern "C" void func_001E6B30(void* s);
extern "C" unsigned char* func_001ED6B8(void* s, unsigned char* p, void* params);
extern "C" void func_001E6AC8(void* s, void* src);
extern "C" unsigned char* func_001ECA68(unsigned char* p);

struct Obj_001EFDC0 {
    char m_pad0[0x10];
    unsigned char* m_10;
    void* m_14;
    void* m_18;
    char m_pad1C[0xA4 - 0x1C];
    int m_A4;
    char m_padA8[0xB0 - 0xA8];
    int m_B0;
    int m_B4;
    int Update();
};

int Obj_001EFDC0::Update()
{
    m_B4 = 0;
    for (;;) {
        if (!m_10) {
            D_0038E7D4 = 0;
            m_B0 = 0;
            return 0;
        }
        D_0038E7D4 = this;
        if (!m_B4) {
            func_001EEF80(this);
        }
        if (m_A4) {
            D_0038E7D4 = 0;
            m_B0 = 0;
            m_B4 = 1;
            return m_A4 == 3 ? 1 : 2;
        }
        switch (*m_10) {
        case 37:
            func_001EF5E0(this);
            break;
        case 38:
            func_001EF6E0(this);
            break;
        case 40:
            func_001EF778(this);
            break;
        case 60:
            func_001EF818(this);
            break;
        case 61:
        case 62:
        case 63:
            func_001EF788(this);
            break;
        case 32:
            func_001EF9C0(this);
            break;
        case 33:
            func_001EFB00(this);
            break;
        case 34:
            func_001EFBE0(this);
            break;
        case 36:
            if (func_001EFCA8(this)) {
                return 5;
            }
            break;
        case 41:
            m_10++;
            func_001E6B30(m_14);
            m_10 = func_001ED6B8(m_14, m_10, m_18);
            if (func_001EFCA8(this)) {
                return 5;
            }
            func_001E6AC8(m_18, m_14);
            break;
        case 46:
        case 47:
        case 55:
        case 64:
        case 65:
            m_10 = func_001ECA68(m_10);
            break;
        case 1:
            m_10++;
            break;
        case 2:
            m_10 += 5;
            break;
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
        case 27:
        case 28:
        case 29:
        case 30:
        case 31:
        case 35:
        case 39:
        case 42:
        case 43:
        case 44:
        case 45:
        case 48:
        case 49:
        case 50:
        case 51:
        case 52:
        case 53:
        case 54:
        case 56:
        case 57:
        case 58:
        case 59:
        default:
            func_001EF228(this);
            break;
        }
    }
}
