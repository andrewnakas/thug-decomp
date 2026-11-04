struct Obj_002D1978_M {
    char pad0[0xC];
    void* mC;
};

extern Obj_002D1978_M* D_00392068;
extern void* D_0038FC78;
extern int D_0039418C;
extern char D_0037B808[];
extern char D_0037B9D8[];
extern char D_0037B9E8[];
extern char D_0037B9F8[];
extern char D_00392B90[];

extern "C" int func_002A6070(Obj_002D1978_M* m);
extern "C" int func_001F0D78(char* s);
extern "C" void* func_00202EF8(int id, int key);
extern "C" void func_001E8890(void* p, char* name, char** out, int v);
extern "C" void func_002E2E88(void* out, char* s);
extern "C" void func_002E2E48(void* out, int v);
extern "C" char* func_002A22D0(Obj_002D1978_M* m, int v);
extern "C" char* func_002A23F0(Obj_002D1978_M* m);
extern "C" int func_002A39F8(Obj_002D1978_M* m);
extern "C" int func_002A1B30(Obj_002D1978_M* m);
extern "C" signed char* func_002A2270(Obj_002D1978_M* m);
extern "C" int func_002A3B50(Obj_002D1978_M* m);
extern "C" int func_002A1FF0(Obj_002D1978_M* m);
extern "C" int func_002A1A48(Obj_002D1978_M* m);
extern "C" int func_002A1968(Obj_002D1978_M* m);
extern "C" void* func_0022E358(void* p);
extern "C" int func_0024F938(void* p);
extern "C" int func_002D7EB8(void* p);

void func_002D1978(void* self, int n, void* out)
{
    Obj_002D1978_M* m = D_00392068;
    void* g = D_0038FC78;
    int id = func_002A6070(m);
    switch (n) {
    case 1: {
        char* s;
        func_001E8890(func_00202EF8(id, func_001F0D78(D_0037B9D8)), D_0037B808, &s, 1);
        func_002E2E88(out, s);
        break;
    }
    case 2:
        func_002E2E88(out, D_0037B9E8);
        break;
    case 4:
        func_002E2E48(out, 0x141E);
        break;
    case 5:
        func_002E2E88(out, func_002A22D0(m, 1));
        break;
    case 6:
    case 11:
        func_002E2E88(out, func_002A23F0(m));
        break;
    case 8:
        func_002E2E48(out, func_002A39F8(m));
        break;
    case 10:
        func_002E2E48(out, func_002A1B30(m));
        break;
    case 19:
        if (*func_002A2270(m) == 0) {
            func_002E2E48(out, 0);
        } else {
            func_002E2E48(out, 1);
        }
        break;
    case 51:
        func_002E2E48(out, func_002A3B50(m));
        break;
    case 52:
        func_002E2E48(out, func_002A1FF0(m));
        break;
    case 53:
        func_002E2E48(out, func_002A1A48(m));
        break;
    case 54:
        if (func_0024F938(func_0022E358(g)) != func_001F0D78(D_0037B9F8)) {
            goto one;
        }
    case 12:
        func_002E2E48(out, 0);
        break;
    one:
        func_002E2E48(out, 1);
        break;
    case 55:
        func_002E2E48(out, func_002A1968(m));
        break;
    case 56:
        func_002E2E48(out, func_002D7EB8(m->mC));
        break;
    default:
        func_002E2E88(out, D_00392B90);
        break;
    }
    D_0039418C = 1;
}
