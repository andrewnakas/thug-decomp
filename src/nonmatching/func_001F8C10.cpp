/* fuzzy: 58.1 */
extern char D_0038EB88[];
extern char D_003F3400[];
extern int D_0039412C;
extern "C" int func_00327248(void* cfg);
extern "C" int func_001F8B38(void* a, void* b, void* c);
extern "C" int func_00327468(char* name);
extern "C" int func_00327578();
extern "C" int func_003276D8(int* state);
extern "C" int func_00327870(int* error);
extern "C" void func_003247E8(int ms);

extern "C" int func_001F8C10(void* cfg, void* a, void* b, void* c, int timeout, void (*callback)(int))
{
    if (func_00327248(cfg)) return 2;
    if (func_001F8B38(a, b, c)) return 4;
    if (func_00327468(D_0038EB88)) return 2;
    int done = 0;
    char* name = D_003F3400;
    do {
        if (func_00327468(name)) return 2;
        if (*name == 0) {
            done = 1;
        } else {
            name += 0x58;
        }
    } while (!done);
    if (func_00327578()) return 2;
    int state = -1;
    int wait = timeout * 1000;
    int prev = -2;
    int up = 0;
    while (!D_0039412C) {
        if (func_003276D8(&state)) return 2;
        if (!up) {
            up = 1;
            if (state < 5 || state > 8) up = 0;
        } else if (state < 5 || state > 8) {
            int error;
            if (func_00327870(&error)) return 2;
            switch (error) {
            case 2: return 8;
            case 3: return 9;
            case 4: return 10;
            case 5: return 11;
            default: return 5;
            }
        }
        if (state == prev) {
            if (wait <= 0) return 6;
            func_003247E8(10);
            wait -= 10;
        } else {
            prev = state;
            if (callback) callback(state);
        }
        if (state == 8) break;
    }
    return 0;
}
