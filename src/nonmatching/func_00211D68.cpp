/* fuzzy: 96.5 */
typedef int qword_00211D68 __attribute__((mode(TI)));

struct Array_00211D68 {
    char pad[0xC];
    unsigned int m_size;
};

struct Net_00211D68 {
    char pad[0xAC];
    unsigned int mAC;
};

struct Game_00211D68 {
    char pad[0x28];
    void* m28;
};

struct Obj_00211D68 {
    char pad[8];
    int m8;
};

struct Color_00211D68 {
    unsigned char r, g, b, a;
    Color_00211D68() {}
    Color_00211D68(const Color_00211D68& o) { *this = o; }
};

struct Vec_00211D68 {
    qword_00211D68 q;
    ~Vec_00211D68() {}
};

struct Light_00211D68 {
    Vec_00211D68 m0;
    float m10;
    float m14;
    float m18;
    Color_00211D68 m1C;
    int m20;
    void SetColor(Color_00211D68 c) { m1C = c; }
    void SetRange(float r)
    {
        m10 = r;
        m14 = 1.0f / r;
    }
};

extern char D_00370540[];
extern char D_00370550[];
extern char D_00370560[];
extern char D_003705A0[];
extern char D_00370678[];
extern char D_00370688[];
extern char D_003706A8[];
extern char D_003706C0[];
extern char D_003706D0[];
extern char D_0038F368[];
extern char D_0038F4B0[];
extern Game_00211D68* D_0038FC78;
extern Net_00211D68* D_00392808;
extern int D_0038881C;

extern "C" void func_0010BFC0(char* s);
extern "C" void func_0010BFC8();
extern "C" void func_00211D10();
extern "C" Array_00211D68* func_001E55B8(unsigned int name, int a);
extern "C" void func_0026AE08(void* p, Array_00211D68* a);
extern "C" void* func_00131E48();
extern "C" void* func_001E9378(Array_00211D68* a, unsigned int i);
extern "C" bool func_001E8398(void* s, unsigned int name, unsigned int* out, int req);
extern "C" void func_001E6B90(void* s, unsigned int name);
extern "C" Obj_00211D68* func_00132FD0(void* m, unsigned int id);
extern "C" void func_00135048(Obj_00211D68* o, int a);
extern "C" void func_001E93D0(void* s, int a);
extern "C" void func_00103F28(char* fmt, ...);
extern "C" bool func_001E8708(void* s, unsigned int name);
extern "C" bool func_0022EEC0(Game_00211D68* g, void* s);
extern "C" void func_00134FD8(Obj_00211D68* o, unsigned int a);
extern "C" void func_001353D8(Obj_00211D68* o, int a);
extern "C" void func_00135438(Obj_00211D68* o, int a);
extern "C" void func_00132078(unsigned int id, int a);
extern "C" bool func_0022EF38(Game_00211D68* g);
extern "C" char* func_001E61F0(unsigned int id);
extern "C" int func_001E86D0(void* s, char* name);
extern "C" bool func_001E5648(char* name, int a);
extern "C" bool func_001E8A50(void* s, char* name, int* out, int req);
extern "C" void* func_0022E048(Game_00211D68* g);
extern "C" void func_00265F58(void* p, int a);
extern "C" void func_00265FF8(void* p, int a, int b);
extern "C" void func_0026B7D8(unsigned int i, bool b);
extern "C" void func_0026C2A8(unsigned int i, bool b);
extern "C" void func_00211410(unsigned int i);
extern "C" void func_0026B9D8(Array_00211D68* a);
extern "C" void func_00269038(void* p);
extern "C" void* func_00230628(Game_00211D68* g);
extern "C" void func_0026D0E0(void* p);
extern "C" int func_00229E30(unsigned int i);
extern "C" void func_00229FF8(void* s, Vec_00211D68* v);
extern "C" bool func_001E7EB0(void* s, unsigned int name, float* out, int req);
extern "C" bool func_001E8248(void* s, unsigned int name, void** out, int req);
extern "C" unsigned char func_001E9270(void* a, int i);
extern "C" Light_00211D68* func_00136268();
extern "C" void func_00136308(int id, Vec_00211D68* pos, Color_00211D68 col, float a, float b);

bool Cmd_00211D68(void* params, void* script)
{
    unsigned int i;
    Vec_00211D68 pos;
    Color_00211D68 col;
    func_0010BFC0(D_00370540);
    func_00211D10();
    Game_00211D68* game = D_0038FC78;
    Array_00211D68* arr = func_001E55B8(0xC472ECC5, 0);
    func_0010BFC0(D_00370550);
    void* p28 = game->m28;
    func_0026AE08(p28, arr);
    func_0010BFC8();
    void* mgr = func_00131E48();
    for (i = 0; i < arr->m_size; i++) {
        void* s = func_001E9378(arr, i);
        unsigned int type = 0;
        func_001E8398(s, 0x12B4E660, &type, 0);
        switch (type) {
        case 0xB7B3BD86: {
            unsigned int id = 0;
            func_001E8398(s, 0xA1DC81F9, &id, 0);
            Obj_00211D68* o = func_00132FD0(mgr, id);
            if (o) func_00135048(o, 0);
            break;
        }
        case 0x8E6B02AD:
            func_001E6B90(s, 0x9D2D0915);
            func_001E6B90(s, 0x7321A8D6);
            break;
        case 0xBF4D3536: {
            func_001E6B90(s, 0x2D7E583B);
            unsigned int id = 0;
            func_001E8398(s, 0xA1DC81F9, &id, 0);
            if (!id) {
                func_001E93D0(s, 0);
                func_00103F28(D_00370560, i);
            }
            Obj_00211D68* o = func_00132FD0(mgr, id);
            if (o) {
                if (D_00392808->mAC != 0xD443A2BC) {
                    if (func_001E8708(s, 0x7C2552B9)) func_0022EEC0(game, s);
                } else {
                    if (!func_001E8708(s, 0x7C2552B9) || func_0022EEC0(game, s)) {
                        func_00135048(o, 0);
                    } else {
                        func_00134FD8(o, 0xFFFFFFFF);
                        func_00135048(o, 1);
                        func_001353D8(o, 1);
                    }
                }
                if (func_001E8708(s, 0x4E549FE1)) {
                    func_00135438(o, 1);
                    func_00135048(o, 0);
                    if (!func_001E8708(s, 0x7C2552B9)) func_00132078(id, 0);
                }
                unsigned int v = 0xE3714DC1;
                func_001E8398(s, 0x7E4813A7, &v, 0);
                o->m8 = v;
            } else {
                if (!func_0022EF38(game)) func_00103F28(D_003705A0, i, func_001E61F0(id));
            }
            int on = func_001E86D0(s, D_00370678);
            if (!D_0038881C) {
                if (func_001E5648(D_00370688, 0)) on = 1;
            }
            if (!func_0022EEC0(game, s) && on) {
                func_0010BFC0(D_003706A8);
                int a;
                func_001E8A50(s, D_0038F368, &a, 1);
                int b = a;
                func_001E8A50(s, D_0038F4B0, &b, 0);
                func_00265F58(func_0022E048(game), b);
                func_00265FF8(func_0022E048(game), a, b);
                func_0010BFC8();
            }
            break;
        }
        }
        if (!func_0022EEC0(game, s)) {
            if (type != 0xBF4D3536 || D_00392808->mAC == 0xD443A2BC) {
                if (type == 0x08470F2E) {
                    func_0010BFC0(D_003706C0);
                    func_0026B7D8(i, func_001E8708(s, 0x7C2552B9));
                    func_0010BFC8();
                }
                if (type == 0xD64DC7C2) {
                    func_0010BFC0(D_003706D0);
                    func_0026C2A8(i, func_001E8708(s, 0x7C2552B9));
                    func_0010BFC8();
                }
                if (func_001E8708(s, 0x7C2552B9)) func_00211410(i);
            }
        }
    }
    func_0026B9D8(arr);
    func_00269038(p28);
    func_0026D0E0(func_00230628(D_0038FC78));
    for (i = 0; i < arr->m_size; i++) {
        void* s = func_001E9378(arr, i);
        unsigned int type = 0;
        func_001E8398(s, 0x12B4E660, &type, 0);
        if (type == 0xA0E52802) {
            bool create = !func_001E8708(s, 0xE1509E4F);
            bool apply = !func_001E8708(s, 0x6F050E18);
            int id = func_00229E30(i);
            func_00229FF8(s, &pos);
            float radius = 100.0f;
            float inner = 300.0f;
            float outer = 300.0f;
            func_001E7EB0(s, 0x2689291C, &radius, 0);
            func_001E7EB0(s, 0x8D2C287F, &inner, 0);
            func_001E7EB0(s, 0x833950CC, &outer, 0);
            func_001E8708(s, 0x7C2552B9);
            col.r = 255;
            col.g = 255;
            col.b = 255;
            col.a = 0;
            void* rgb;
            func_001E8248(s, 0x99A9B716, &rgb, 0);
            if (rgb) {
                col.r = func_001E9270(rgb, 0);
                col.g = func_001E9270(rgb, 1);
                col.b = func_001E9270(rgb, 2);
            }
            if (create) {
                Light_00211D68* l = func_00136268();
                if (l) {
                    l->m20 = id;
                    l->m0 = pos;
                    l->m18 = radius * 0.01f;
                    l->SetColor(col);
                    l->SetRange(outer);
                }
            }
            if (apply) func_00136308(id, &pos, col, radius, outer);
        }
    }
    func_0010BFC8();
    return true;
}
