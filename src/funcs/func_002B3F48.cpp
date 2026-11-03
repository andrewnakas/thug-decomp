extern char D_00392470[];
extern char D_00392478[];

struct G_002B3F48 {
    char pad[0x99D4];
    char m99D4[0x400];
    char pad9DD4[8];
    int m9DDC;
};

extern G_002B3F48* D_00392068;
extern "C" char* func_00332088(char* dst, const char* src, int n);
extern "C" char* func_00336558(char* s, char* delim);
extern "C" int func_00334120(char* s);
extern "C" int func_00331BB8(char* s);
extern "C" int func_001F0D78(char* s);
extern "C" void func_002B5608(G_002B3F48* g, int state);

extern "C" bool func_002B3F48(void* self, int err, char* text)
{
    int ok = 0;
    G_002B3F48* g = D_00392068;
    if (!err) {
        char buf[0x1000];
        func_00332088(buf, text, 0xFFF);
        buf[0xFFF] = 0;
        char* tok = func_00336558(buf, D_00392470);
        if (tok) {
            int v = func_00334120(tok);
            if (v == func_001F0D78(tok + func_00331BB8(tok) + 1)) {
                char* t1 = func_00336558(0, D_00392470);
                if (t1) {
                    char* t2 = func_00336558(0, D_00392478);
                    if (t2) {
                        func_00332088(g->m99D4, t2, 0x3FF);
                        ok = 1;
                        g->m99D4[0x3FF] = 0;
                        func_00334120(t1);
                    }
                }
            }
        }
        if (ok) {
            g->m9DDC = 1;
            func_002B5608(g, 5);
        }
    }
    if (!ok)
        func_002B5608(g, 8);
    return true;
}
