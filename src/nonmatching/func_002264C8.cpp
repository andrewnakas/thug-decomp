/* fuzzy: 90.2 */
typedef int qword_002264C8 __attribute__((mode(TI)));

extern char D_0038F9D0[];
extern char D_0038F9F0[];
extern char D_0038FA08[];
extern int D_0038FA10[];
extern char D_0038FA18[];
extern char D_003720D0[];
extern char D_00372110[];
extern char D_00372120[];
extern char D_00372138[];
extern char D_00372148[];
extern char D_00372160[];
extern char D_00372170[];
extern char D_00372188[];
extern char D_00372198[];
extern char D_003721B0[];
extern char D_003721C0[];

struct Vec_002264C8 {
    union {
        qword_002264C8 q;
        struct {
            float x, y, z, w;
        } f;
        struct {
            int r, g, b, a;
        } c;
    };
};

struct Lights_002264C8 {
    Vec_002264C8 col[3];
};

/* The colour and lighting block of a PS2 icon.sys file. */
struct IconColors_002264C8 {
    Vec_002264C8 bg[4];
    Vec_002264C8 dir[3];
    Lights_002264C8 lights;
    Vec_002264C8 ambient;
};

struct IconSys_002264C8 {
    char magic[4];
    short reserved;
    short lineBreak;
    int pad8;
    int bgAlpha;
    IconColors_002264C8 colors;
    char title[68];
    char iconFile[64];
    char copyFile[64];
    char delFile[64];
    char padRest[0x200];
};

extern Lights_002264C8 D_003720E0;

struct Heap_002264C8 {
    char pad[0xD8];
    void* m_D8;
};

extern Heap_002264C8* D_00388A70;

struct Card_002264C8 {
    char pad[0xC];
    int m_error;
};

class File_002264C8 {
public:
    char pad[0x14];
    virtual ~File_002264C8();
};

extern "C" void func_00226478(unsigned int type, char* name, char* out);
extern "C" bool func_001130B0(Card_002264C8* card, char* name);
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" void* func_003315B8(void* p, int c, int n);
extern "C" char* func_001E5488(unsigned int key, int a);
extern "C" char* func_00331A9C(char* dst, const char* src);
extern "C" int func_00331BB8(const char* s);
extern "C" char* func_00331678(char* dst, const char* src);
extern "C" unsigned short func_00224490(unsigned char c);
extern "C" void func_0010FE68();
extern "C" void* func_00110E38(char* name, char* mode);
extern "C" long func_00110980(void* fh);
extern "C" void func_0010A950(Heap_002264C8* heap, void* a);
extern "C" void* func_0010BDE0(unsigned int size);
extern "C" void func_0010A9B0(Heap_002264C8* heap);
extern "C" int func_00110F68(void* buf, int a, int size, void* fh);
extern "C" int func_00110EF8(void* fh);
extern "C" File_002264C8* func_00113380(Card_002264C8* card, char* name, int mode, int a);
extern "C" int func_00113AC0(File_002264C8* f, void* buf, int size);
extern "C" bool func_00113A70(File_002264C8* f);
extern "C" bool func_00113988(File_002264C8* f);
extern "C" void func_0010BEB8(void* p);

/* Creates the save's memory card directory: returns true at once if its icon.sys exists;
   otherwise makes the directory, writes icon.sys (title in SJIS, colours, lights) and the icon file. */
bool func_002264C8(Card_002264C8* card, unsigned int type, char* name, char* outName, int* err)
{
    char dir[112];
    char path[112];
    IconSys_002264C8 icon;
    IconColors_002264C8 colors;
    char title[112];
    char iconPath[112];

    func_00226478(type, name, dir);
    func_003331D0(outName, D_0038FA08, dir, dir);
    func_003331D0(path, D_003720D0, dir);
    File_002264C8* f = func_00113380(card, path, 1, 0);
    if (f) {
        func_00113A70(f);
        func_00113988(f);
        delete f;
        return true;
    }
    if (!func_001130B0(card, dir)) {
        if (card->m_error == 2)
            *err = 1;
        return false;
    }

    int lineLen = 16;
    func_003315B8(colors.bg, 0, sizeof(colors.bg));
    colors.bg[0].c.r = 0x80;
    colors.bg[1].c.g = 0x80;
    colors.bg[2].c.b = 0x80;
    colors.bg[3].c.r = 0x80;
    colors.bg[3].c.g = 0x80;
    colors.bg[3].c.b = 0x80;
    func_003315B8(colors.dir, 0, sizeof(colors.dir));
    colors.dir[0].f.x = 0.5f;
    colors.dir[1].f.y = 0.5f;
    colors.dir[2].f.z = 0.5f;
    colors.lights = D_003720E0;
    colors.ambient.f.x = 0.5f;
    colors.ambient.f.y = 0.5f;
    colors.ambient.f.z = 0.5f;
    colors.ambient.f.w = 0.0f;
    func_003315B8(&icon, 0, 0x3C4);
    __builtin_memcpy(icon.magic, D_0038FA10, 5);

    char* iconName = D_0038F9D0;
    char* image = D_0038F9D0;
    switch (type) {
    case 0xB010F357:
        func_00331A9C(title, func_001E5488(0x130AB28A, 0));
        lineLen = func_00331BB8(title);
        func_00331678(title, name);
        iconName = D_00372110;
        image = D_00372120;
        break;
    case 0xCA41692D:
        func_00331A9C(title, func_001E5488(0x92C497AE, 0));
        lineLen = func_00331BB8(title);
        func_00331678(title, name);
        iconName = D_00372138;
        image = D_00372148;
        break;
    case 0x61A1BC57:
        func_00331A9C(title, func_001E5488(0x3AA2CFFA, 0));
        lineLen = func_00331BB8(title);
        func_00331678(title, name);
        iconName = D_00372160;
        image = D_00372170;
        break;
    case 0x62896EDF:
        func_00331A9C(title, func_001E5488(0x257678CB, 0));
        lineLen = func_00331BB8(title);
        func_00331678(title, name);
        iconName = D_00372188;
        image = D_00372198;
        break;
    case 0x3BF882CC:
        func_00331A9C(title, func_001E5488(0x2171FDDC, 0));
        lineLen = func_00331BB8(title);
        func_00331678(title, name);
        iconName = D_003721B0;
        image = D_003721C0;
        break;
    }

    int len = func_00331BB8(title);
    title[32] = 0;
    char* out = icon.title;
    for (int i = 0; i < len; i++) {
        unsigned short c = func_00224490(title[i]);
        *out++ = c >> 8;
        *out++ = c;
    }
    out[0] = 0;
    out[1] = 0;
    icon.lineBreak = lineLen * 2;
    icon.bgAlpha = 0x60;
    __builtin_memcpy(icon.colors.bg, colors.bg, sizeof(colors.bg));
    __builtin_memcpy(icon.colors.dir, colors.dir, sizeof(colors.dir));
    __builtin_memcpy(&icon.colors.lights, &colors.lights, sizeof(colors.lights));
    __builtin_memcpy(&icon.colors.ambient, &colors.ambient, sizeof(colors.ambient));

    func_00331A9C(icon.iconFile, iconName);
    func_00331A9C(icon.copyFile, iconName);
    func_00331A9C(icon.delFile, iconName);

    bool ok = false;
    func_0010FE68();
    void* fh = func_00110E38(image, D_0038F9F0);
    int size = func_00110980(fh);
    func_0010A950(D_00388A70, D_00388A70->m_D8);
    void* buf = func_0010BDE0((size + 0x7FF) & 0xFFFFF800);
    func_0010A9B0(D_00388A70);
    func_00110F68(buf, 1, size, fh);
    func_00110EF8(fh);

    f = func_00113380(card, path, 6, 0);
    if (card->m_error == 2)
        *err = 1;
    if (f) {
        int written = func_00113AC0(f, &icon, 0x3C4);
        if (card->m_error == 2)
            *err = 1;
        ok = written == 0x3C4;
        if (!func_00113A70(f))
            ok = false;
        if (!func_00113988(f))
            ok = false;
        delete f;
    }
    if (!ok) {
        func_0010BEB8(buf);
        return false;
    }

    func_003331D0(iconPath, D_0038FA18, dir, iconName);
    ok = false;
    f = func_00113380(card, iconPath, 6, 0);
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
