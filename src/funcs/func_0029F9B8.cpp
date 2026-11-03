extern "C" int func_00113E98(char* ev);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" int func_001F0D78(char* s);
extern "C" void func_001E7360(void* s, unsigned int name, unsigned int v);
extern "C" int func_0018A370(void* s, int v);
extern "C" void func_001E6B30(void* s);
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" void func_00113EE8();
extern "C" unsigned int func_0010FC30();
extern "C" void func_001E6AE8(void* p, int v);
extern char D_00392090[];
extern char D_00377DB8[];
extern char D_00377DC8[];
extern char D_00377DE0[];
extern char D_00377DF8[];
extern char D_00377E08[];
extern unsigned int D_0039208C;

static inline bool Elapsed_0029F9B8(unsigned int ms, unsigned int now, unsigned int start)
{
    return now - start > ms;
}

void func_0029F9B8()
{
    char ev[0x100];
    if (func_00113E98(ev) <= 0) return;
    if (ev[0] == 0x19 || ev[0] == 0x20) {
        void* s = func_001E6978(func_001190D0(8));
        func_001E7360(s, func_001F0D78(D_00392090), func_001F0D78(D_00377DB8));
        if (func_0018A370(s, 0)) return;
        func_001E6B30(s);
        func_001E7360(s, func_001F0D78(D_00392090), func_001F0D78(D_00377DC8));
        if (func_0018A370(s, 0)) return;
        func_001E6B30(s);
        func_001E7360(s, func_001F0D78(D_00392090), func_001F0D78(D_00377DE0));
        if (func_0018A370(s, 0)) return;
        func_001F0370(D_00377DF8, 0, 0, 0);
        func_00113EE8();
        return;
    } else if (ev[0] == 0x1B) {
        if (Elapsed_0029F9B8(2000, func_0010FC30(), D_0039208C)) {
            void* s = func_001E6978(func_001190D0(8));
            func_001E7360(s, 0xB53D0E0F, 0x0E5FD359);
            func_001F0370(D_00377E08, s, 0, 0);
            if (s) func_001E6AE8(s, 3);
            D_0039208C = func_0010FC30();
        }
    } else if (ev[0] == 0x1C) {
        if (Elapsed_0029F9B8(2000, func_0010FC30(), D_0039208C)) {
            void* s = func_001E6978(func_001190D0(8));
            func_001E7360(s, 0xB53D0E0F, 0xBEEA3518);
            func_001F0370(D_00377E08, s, 0, 0);
            if (s) func_001E6AE8(s, 3);
            D_0039208C = func_0010FC30();
        }
    } else if (ev[0] == 0x1D) {
        if (Elapsed_0029F9B8(2000, func_0010FC30(), D_0039208C)) {
            void* s = func_001E6978(func_001190D0(8));
            func_001E7360(s, 0xB53D0E0F, 0x4525ADBD);
            func_001F0370(D_00377E08, s, 0, 0);
            if (s) func_001E6AE8(s, 3);
            D_0039208C = func_0010FC30();
        }
    } else if (ev[0] == 0x1E) {
        if (Elapsed_0029F9B8(2000, func_0010FC30(), D_0039208C)) {
            void* s = func_001E6978(func_001190D0(8));
            func_001E7360(s, 0xB53D0E0F, 0xA36DBEE1);
            func_001F0370(D_00377E08, s, 0, 0);
            if (s) func_001E6AE8(s, 3);
            D_0039208C = func_0010FC30();
        }
    }
}
