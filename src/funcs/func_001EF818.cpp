struct Comp_001EF818;

extern "C" void func_001E6B30(void* s);
extern "C" unsigned char* func_001ED6B8(void* s, unsigned char* p, void* params);
extern "C" void* func_001E8CD0(int size);
extern "C" Comp_001EF818* func_001E4ED8(void* mem);
extern "C" void* func_001E6E90(void* s, int a);
extern "C" void func_001E6360(Comp_001EF818* c, void* v);
extern "C" int func_001EA928(Comp_001EF818* c, void* v);
extern "C" unsigned char* func_001EC880(unsigned char* p);
extern "C" unsigned char* func_001EB070(unsigned char* p);
extern "C" void func_001E6250(Comp_001EF818* c);
extern "C" void func_001E8D20(Comp_001EF818* c);

struct Obj_001EF818 {
    char m_pad0[0x10];
    unsigned char* m_10;
    void* m_14;
    void* m_18;
    void Switch();
};

extern "C" void func_001EF788(Obj_001EF818* self);

void Obj_001EF818::Switch()
{
    m_10++;
    func_001E6B30(m_14);
    m_10 = func_001ED6B8(m_14, m_10, m_18);
    Comp_001EF818* c = func_001E4ED8(func_001E8CD0(0x10));
    void* v = func_001E6E90(m_14, 0);
    if (v) {
        func_001E6360(c, v);
    }
    int done = 0;
    while (!done) {
        switch (*m_10) {
        case 0x24:
            break;
        case 0x3C:
            m_10++;
            func_001EF788(this);
            break;
        case 0x3E:
            m_10++;
            func_001E6B30(m_14);
            m_10 = func_001ED6B8(m_14, m_10, m_18);
            v = func_001E6E90(m_14, 0);
            if (v && func_001EA928(c, v)) {
                done = 1;
            }
            if (done) {
                do {
                    m_10 = func_001EC880(m_10);
                    if (*m_10 != 0x3E) {
                        break;
                    }
                    m_10++;
                    func_001E6B30(m_14);
                    m_10 = func_001ED6B8(m_14, m_10, m_18);
                } while (true);
            }
            break;
        case 0x3D:
        case 0x3F:
            m_10++;
            done = 1;
            break;
        case 0x25:
        case 0x26:
        case 0x27:
        case 0x28:
        case 0x29:
        case 0x2A:
        case 0x2B:
        case 0x2C:
        case 0x2D:
        case 0x2E:
        case 0x2F:
        case 0x30:
        case 0x31:
        case 0x32:
        case 0x33:
        case 0x34:
        case 0x35:
        case 0x36:
        case 0x37:
        case 0x38:
        case 0x39:
        case 0x3A:
        case 0x3B:
        default:
            m_10 = func_001EB070(m_10);
            break;
        }
    }
    func_001E6250(c);
    func_001E8D20(c);
}
