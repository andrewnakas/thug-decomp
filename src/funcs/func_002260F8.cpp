extern char D_0038F9E8[];
extern char D_0038F9D0[];
extern char D_0038F9F0[];
extern char D_0038F9F8[];
extern char D_00372010[];
extern char D_00372020[];
extern char D_00372050[];
extern char D_00372078[];
extern char D_003720A8[];

struct Heap_002260F8 {
    char pad[0xD8];
    void* m_D8;
};

extern Heap_002260F8* D_00388A70;

struct Card_002260F8 {
    char pad[0xC];
    int m_error;
};

class File_002260F8 {
public:
    char pad[0x14];
    virtual ~File_002260F8();
};

extern "C" char* func_00225FE8(unsigned int type, char* name);
extern "C" bool func_001130B0(Card_002260F8* card, char* name);
extern "C" char* func_00113130(Card_002260F8* card, char* name);
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" char* func_001E5488(unsigned int key, int a);
extern "C" char* func_00331A9C(char* dst, const char* src);
extern "C" char* func_00331678(char* dst, const char* src);
extern "C" void func_0010FE68();
extern "C" void* func_00110E38(char* name, char* mode);
extern "C" long func_00110980(void* fh);
extern "C" void func_0010A950(Heap_002260F8* heap, void* a);
extern "C" void* func_0010BDE0(unsigned int size);
extern "C" void func_0010A9B0(Heap_002260F8* heap);
extern "C" int func_00110F68(void* buf, int a, int size, void* fh);
extern "C" int func_00110EF8(void* fh);
extern "C" File_002260F8* func_00113380(Card_002260F8* card, char* name, int mode, int a);
extern "C" int func_00113AC0(File_002260F8* f, void* buf, int size);
extern "C" bool func_00113A70(File_002260F8* f);
extern "C" bool func_00113988(File_002260F8* f);
extern "C" void func_0010BEB8(void* p);

bool func_002260F8(Card_002260F8* card, unsigned int type, char* name, char* outName, int* err)
{
    outName[0] = 0;
    char* fname = func_00225FE8(type, name);
    if (!func_001130B0(card, fname)) {
        if (card->m_error == 2)
            *err = 1;
        return false;
    }
    char* dir = func_00113130(card, fname);
    if (!dir)
        return false;
    func_003331D0(outName, D_0038F9E8, dir, dir);
    char desc[112];
    char path[112];
    char* icon = D_0038F9D0;
    char* image = D_0038F9D0;
    switch (type) {
    case 0xB010F357:
        func_00331A9C(desc, func_001E5488(0x130AB28A, 0));
        func_00331678(desc, name);
        icon = D_00372010;
        image = D_00372020;
        break;
    case 0xCA41692D:
        func_00331A9C(desc, func_001E5488(0x92C497AE, 0));
        func_00331678(desc, name);
        icon = D_00372010;
        image = D_00372020;
        break;
    case 0x62896EDF:
        func_00331A9C(desc, func_001E5488(0x257678CB, 0));
        func_00331678(desc, name);
        icon = D_00372010;
        image = D_00372050;
        break;
    case 0x61A1BC57:
        func_00331A9C(desc, func_001E5488(0x3AA2CFFA, 0));
        func_00331678(desc, name);
        icon = D_00372010;
        image = D_00372078;
        break;
    case 0x3BF882CC:
        func_00331A9C(desc, func_001E5488(0x2171FDDC, 0));
        func_00331678(desc, name);
        icon = D_00372010;
        image = D_003720A8;
        break;
    case 0x26C80B0D:
    case 0xFFFFFFFF:
        break;
    }
    bool ok = false;
    func_0010FE68();
    void* fh = func_00110E38(image, D_0038F9F0);
    int size = func_00110980(fh);
    func_0010A950(D_00388A70, D_00388A70->m_D8);
    void* buf = func_0010BDE0((size + 0x7FF) & 0xFFFFF800);
    func_0010A9B0(D_00388A70);
    func_00110F68(buf, 1, size, fh);
    func_00110EF8(fh);
    func_003331D0(path, D_0038F9F8, dir, icon);
    File_002260F8* f = func_00113380(card, path, 6, 0);
    if (card->m_error == 2)
        *err = 1;
    if (f) {
        int written = func_00113AC0(f, buf, size);
        if (card->m_error == 2)
            *err = 1;
        ok = written == size;
        if (!func_00113A70(f))
            ok = false;
        if (!func_00113988(f))
            ok = false;
        delete f;
    }
    func_0010BEB8(buf);
    return ok;
}
