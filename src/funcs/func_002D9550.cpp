struct Rec_002D9550 {
    int m0;
    int a[12];
    int b[12];
};

struct State_002D9550 {
    int m0;
    int m4;
    int m8;
};

struct Glob_002D9550 {
    char pad[0x10];
    State_002D9550* m10;
};

extern Glob_002D9550* D_00392068;
extern char D_00392E78[];
extern char D_0037C7E0[];
extern char D_0037C7F0[];
extern char D_0037C800[];
extern "C" Rec_002D9550* func_002DA188(void* p);
extern "C" char* func_00336558(char* s, char* sep);
extern "C" int func_00334120(char* s);
extern "C" int func_00336228(char* a, char* b);
extern "C" void func_001F0370(char* s, int a, int b, int c);

void func_002D9550(void* a0, void* a1, void* a2, int idx, int len, char* line)
{
    Glob_002D9550* g = D_00392068;
    if (len <= 0) return;
    Rec_002D9550* rec = func_002DA188(g->m10);
    if (idx == 0) {
        if (func_00336558(line, D_00392E78)) rec->m0 = func_00334120(func_00336558(0, D_00392E78));
        return;
    }
    char* tok = func_00336558(line, D_00392E78);
    if (tok) {
        if (!func_00336228(tok, D_0037C7E0)) {
            tok = func_00336558(0, D_00392E78);
            if (tok) rec->a[idx - 1] = func_00334120(tok);
            tok = func_00336558(0, D_00392E78);
        }
        if (!func_00336228(tok, D_0037C7F0)) {
            tok = func_00336558(0, D_00392E78);
            if (tok) rec->b[idx - 1] = func_00334120(tok);
        }
    }
    if (idx == 11) {
        func_001F0370(D_0037C800, 0, 0, 0);
        g->m10->m8 = 4;
    }
}
