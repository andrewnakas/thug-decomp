struct Heap_002CF018 {
    char pad[0xDC];
    int mDC;
};

struct Info_002CF018 {
    int m0;
    int m4;
    int m8;
    int mC;
};

extern Heap_002CF018* D_00388A70;
extern int D_0038881C;
extern int D_00388814;
extern int D_0038880C;
extern int D_0038882C;
extern int D_00392A48;
extern char D_100B280[];
extern "C" void func_00106838();
/* the size operand is a code label inside func_00106838: (char*)func_00106838 + 0x81 = .L001068B8 + 1 */
extern char D_0037B018[];
extern char D_0037B028[];
extern char D_00392A80[];

extern "C" int func_0010A6D0(Heap_002CF018* h);
extern "C" void func_0010A950(Heap_002CF018* h, int v);
extern "C" char* func_0010A638(Heap_002CF018* h, int size, int a, int b);
extern "C" void func_0010A9B0(Heap_002CF018* h);
extern "C" void func_0010A8D8(Heap_002CF018* h, void* p);
extern "C" void* func_003315B8(void* d, int c, int n);
extern "C" void* func_00110E38(const char* name, char* mode);
extern "C" int func_00110F68(void* buf, int size, int n, void* f);
extern "C" int func_00110EF8(void* f);
extern "C" void func_003288E0(int a);
extern "C" void func_003291C0(int a);
extern "C" void func_00328DB8(int a);
extern "C" int func_002CE7F0(int a, int b, int c, int d, Info_002CF018* info);
extern "C" void* func_001190D0(int n);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6AE8(void* o, int n);
extern "C" void func_001E7200(void* s, unsigned int id, int v);
extern "C" void func_001E70C0(void* s, unsigned int id, char* v);
extern "C" char* func_001E5488(unsigned int id, int v);
extern "C" unsigned int func_002CEC48(int v);
extern "C" unsigned int func_002CEEE8(int v);
extern "C" unsigned int func_002CEDF8(int v);
extern "C" void func_001F0210(unsigned int id, void* s, int a, int b, int c);

int func_002CF018()
{
    Info_002CF018 info;
    if (D_0038881C && D_00388814 == 3)
        goto fail;
    if (func_0010A6D0(D_00388A70) > 0x1B3332) {
        func_0010A950(D_00388A70, D_00388A70->mDC);
        char* buf = func_0010A638(D_00388A70, 0x1B3333, 1, 0);
        func_0010A9B0(D_00388A70);
        if (buf + 0x1B3333 < D_100B280 + (int)((char*)func_00106838 + 0x81) || D_100B280 < buf) {
            if (buf)
                func_0010A8D8(D_00388A70, buf);
            goto fail;
        }
        func_003315B8(D_100B280, 0, (int)((char*)func_00106838 + 0x81));
        void* f;
        if (D_0038880C == 2 && D_0038882C == 1)
            f = func_00110E38(D_0037B018, D_00392A80);
        else
            f = func_00110E38(D_0037B028, D_00392A80);
        func_00110F68(D_100B280, 1, (int)((char*)func_00106838 + 0x81), f);
        func_00110EF8(f);
        if (!D_0038881C) {
            func_003288E0(0);
            func_003291C0(2);
            func_00328DB8(0);
        }
        func_003315B8(&info, 0, 0x10);
        int ok = func_002CE7F0(0, 0, 0, D_00392A48 + 0x1E, &info);
        if (buf)
            func_0010A8D8(D_00388A70, buf);
        if (ok) {
            D_00392A48 += 10;
            void* s = func_001E6978(func_001190D0(8));
            unsigned int a;
            unsigned int b;
            if (!info.m0) {
                func_001E7200(s, 0x88EACF67, 0);
                func_001E7200(s, 0xAF7C50A6, 0);
                a = 0xC7C67EB8;
                b = !D_0038882C ? 0xC13153CC : 0x16FF6A40;
            } else {
                func_001E7200(s, 0x88EACF67, info.m0);
                func_001E7200(s, 0xAF7C50A6, info.m4);
                a = func_002CEC48(info.m4);
                if (!D_0038882C)
                    b = func_002CEEE8(info.m4);
                else
                    b = func_002CEDF8(info.m4);
            }
            char* sa = func_001E5488(a, 1);
            char* sb = func_001E5488(b, 1);
            func_001E70C0(s, 0xF44A53AB, sa);
            func_001E70C0(s, 0x1DCEFAAC, sb);
            func_001F0210(0xC3BB2B5A, s, 0, 0, 0);
            if (s)
                func_001E6AE8(s, 3);
            return 0;
        }
    }
fail:
    func_001F0210(0xBD54C02B, 0, 0, 0, 0);
    D_00392A48 = 0;
    return 1;
}
