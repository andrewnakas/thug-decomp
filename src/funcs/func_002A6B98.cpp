struct Prefs_002A6B98 {
    char pad[0xAC];
    unsigned int mAC;
};
extern void* D_0038FC78;
extern Prefs_002A6B98* D_00392808;
extern char D_00378878[];
struct Obj_002A6B98;
extern "C" int func_00100030(int n);
extern "C" int func_002A19A8(Obj_002A6B98* o);
extern "C" void* func_0022E358(void* p);
extern "C" int func_0024F750(void* p);
extern "C" int func_0024F8D8(void* p, char* s);

struct Obj_002A6B98 {
    char pad[0x50];
    int m50[8];
    int m70;
    void Shuffle();
};

void Obj_002A6B98::Shuffle()
{
    int base = func_00100030(256);
    int n;
    if (func_002A19A8(this)) {
        n = 8;
    } else {
        void* g = D_0038FC78;
        n = func_0024F750(func_0022E358(g));
        if (D_00392808->mAC != 0xD443A2BC && !func_0024F8D8(func_0022E358(g), D_00378878)) {
            n = 2;
            base = 0;
        }
    }
    int i;
    for (i = 0; i < n; i++) m50[i] = -1;
    for (i = 0; i < n; i++) {
        bool unique;
        do {
            m50[i] = func_00100030(n);
            unique = true;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (m50[i] == m50[j]) {
                    unique = false;
                    break;
                }
            }
        } while (!unique);
    }
    for (i = 0; i < n; i++) m50[i] += base;
    m70 = func_00100030(10);
}
