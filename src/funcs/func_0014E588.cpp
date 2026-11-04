extern "C" void* func_001046B0(unsigned int size);

class Comp_00152E08 {
public:
    char m_pad[0x250];
    Comp_00152E08(int owner, int n, int id, int a, int b, int c, float f, int d);
    static void* operator new(unsigned int size) { return func_001046B0(size); }
};

class Comp_001538C8 {
public:
    char m_pad[0x230];
    Comp_001538C8(int owner, int n, int id, int a, int b, int c, float f, int d);
    static void* operator new(unsigned int size) { return func_001046B0(size); }
};

class Comp_00154348 {
public:
    char m_pad[0x240];
    Comp_00154348(int owner, int n, int id, int a, int b, int c, float f, int d);
    static void* operator new(unsigned int size) { return func_001046B0(size); }
};

class Comp_00155170 {
public:
    char m_pad[0x240];
    Comp_00155170(int owner, int n, int id, int a, int b, int c, float f, int d);
    static void* operator new(unsigned int size) { return func_001046B0(size); }
};

class Comp_00155ED0 {
public:
    char m_pad[0x240];
    Comp_00155ED0(int owner, int n, int id, int a, int b, int c, float f, int d);
    static void* operator new(unsigned int size) { return func_001046B0(size); }
};

class Comp_00156D98 {
public:
    char m_pad[0x230];
    Comp_00156D98(int owner, int n, int id, int a, int b, int c, float f, int d);
    static void* operator new(unsigned int size) { return func_001046B0(size); }
};

class Comp_00157700 {
public:
    char m_pad[0x240];
    Comp_00157700(int owner, int n, int id, int a, int b, int c, float f, int d);
    static void* operator new(unsigned int size) { return func_001046B0(size); }
};

class Comp_00158248 {
public:
    char m_pad[0x230];
    Comp_00158248(int owner, int n, int id, int a, int b, int c, float f, int d);
    static void* operator new(unsigned int size) { return func_001046B0(size); }
};

class Comp_00159060 {
public:
    char m_pad[0x250];
    Comp_00159060(int owner, int n, int id, int a, int b, int c, float f, int d);
    static void* operator new(unsigned int size) { return func_001046B0(size); }
};

class Comp_00159BC8 {
public:
    char m_pad[0x230];
    Comp_00159BC8(int owner, int n, int id, int a, int b, int c, float f, int d);
    static void* operator new(unsigned int size) { return func_001046B0(size); }
};

class Comp_0015E960 {
public:
    char m_pad[0x3C0];
    Comp_0015E960(int owner, int key, int id, int a, int b);
    static void* operator new(unsigned int size) { return func_001046B0(size); }
};

class Comp_00152350 {
public:
    char m_pad[0x220];
    Comp_00152350(int owner, int n, int id, int a, int b, int c, float f, int d);
    static void* operator new(unsigned int size) { return func_001046B0(size); }
};

extern "C" void* func_0014E588(int owner, unsigned int type, int n, int key, int id, int a, int b, int c, float f, int d)
{
    switch (type) {
    case 0xF4D8D486:
        return new Comp_00152E08(owner, n, id, a, b, c, f, d);
    case 0x8ADDAC1F:
        return new Comp_001538C8(owner, n, id, a, b, c, f, d);
    case 0x15834EEA:
        return new Comp_00154348(owner, n, id, a, b, c, f, d);
    case 0x3624A5EB:
        return new Comp_00155170(owner, n, id, a, b, c, f, d);
    case 0x097CB7A9:
        return new Comp_00155ED0(owner, n, id, a, b, c, f, d);
    case 0x2EEB4B09:
        return new Comp_00156D98(owner, n, id, a, b, c, f, d);
    case 0x0EE6FC5B:
        return new Comp_00157700(owner, n, id, a, b, c, f, d);
    case 0xC4D5A4CB:
        return new Comp_00158248(owner, n, id, a, b, c, f, d);
    case 0x3F109FCC:
        return new Comp_00159060(owner, n, id, a, b, c, f, d);
    case 0x7EC7252D:
        return new Comp_00159BC8(owner, n, id, a, b, c, f, d);
    case 0xDEDFC057:
        return new Comp_0015E960(owner, key, id, a, b);
    case 0xAAB555BB:
    default:
        return new Comp_00152350(owner, n, id, a, b, c, f, d);
    }
}
