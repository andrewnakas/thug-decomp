/* fuzzy: 91.3 */
/* sym: __12Str_002527B0PCc = 0x00104028 */
/* sym: _$_12Str_002527B0 = 0x001040A8 */
/* sym: __12Str_002527B0RC12Str_002527B0 = 0x00104068 */
/* sym: Get__C12Str_002527B0 = 0x001041B8 */
extern "C" void* memcpy(void*, const void*, unsigned int);

struct Str_002527B0 {
    char* m_p;
    Str_002527B0(const char* s);
    Str_002527B0(const Str_002527B0& o);
    ~Str_002527B0();
    const char* Get() const;
};

struct Obj_002527B0 {
    char pad0[4];
    int m4;
    int m8;
    char padC[0x210 - 0xC];
    char m210[4];
};

struct Skater_002527B0 {
    char pad[0x18];
    int m18;
};

extern long D_00390750[];
extern char D_00390748[];
extern char D_00390758[];
extern char D_00390760[];
extern char D_00374E20[];
extern char D_00374E38[];
extern char D_00374E50[];
extern char D_00374E60[];
extern char D_00374E70[];
extern void* D_0038FC78;

extern "C" Skater_002527B0* func_0022DF08(void* self, int id);
extern "C" char* func_00206A08(Skater_002527B0* s);
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" char* func_00331A9C(char* dst, const char* src);
extern "C" char* func_001E5518(char* name, int a);
extern "C" char* func_001044A8(int v, int sep);
extern "C" Str_002527B0 func_00252608(Obj_002527B0* o, int idx);
extern "C" char* func_002526B8(Obj_002527B0* o);
extern "C" unsigned int func_001F0D78(const char* s);

Str_002527B0 GetText_002527B0(Obj_002527B0* o, unsigned int key)
{
    char buf[256];
    memcpy(buf, D_00390750, 8);
    void* net = D_0038FC78;
    Skater_002527B0* sk = func_0022DF08(net, o->m8);
    switch (key) {
    case 0x9196D920:
        func_003331D0(buf, D_00390758, func_00206A08(func_0022DF08(net, sk->m18)));
        break;
    case 0x5078BC7C:
        if (o->m4 > 0)
            func_003331D0(buf, D_00390748, func_001E5518(D_00374E20, 0), func_001044A8(o->m4, ','));
        else
            func_003331D0(buf, func_001E5518(D_00374E38, 0));
        break;
    case 0x2A13F850:
        func_00331A9C(buf, o->m210);
        break;
    case 0xDE802177:
        func_003331D0(buf, D_00390760, func_00206A08(func_0022DF08(net, 0)), func_00252608(o, 0).Get());
        break;
    case 0x478970CD:
        func_003331D0(buf, D_00390760, func_00206A08(func_0022DF08(net, 1)), func_00252608(o, 1).Get());
        break;
    case 0x2523853D: {
        char c = *func_002526B8(o);
        bool vowel = false;
        unsigned char d = c - 'a';
        if (d < 26)
            c = d + 'A';
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            vowel = true;
        func_003331D0(buf, D_00390748, GetText_002527B0(o, func_001F0D78(D_00374E50)).Get(),
                      vowel ? func_001E5518(D_00374E60, 0) : func_001E5518(D_00374E70, 0));
        break;
    }
    case 0x5F7D73E9:
        func_003331D0(buf, D_00390758, func_002526B8(o));
        break;
    }
    return Str_002527B0(buf);
}
