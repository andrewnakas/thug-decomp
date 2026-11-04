struct Skater_0021D560 {
    char pad0[0x230];
    int m230;
};

extern void* D_0038FC78;
extern char D_0038F838[];
extern char D_0038F840[];
extern "C" int func_001E87B8(void* params, char* name);
extern "C" Skater_0021D560* func_0022DE70(void* game, int i);

bool Cmd_0021D560(void* params, void* script)
{
    int on = func_001E87B8(params, D_0038F838);
    int off = func_001E87B8(params, D_0038F840);
    for (int i = 0; i < 8; i++) {
        Skater_0021D560* s = func_0022DE70(D_0038FC78, i);
        if (s) {
            if (on)
                s->m230 = 1;
            else if (off)
                s->m230 = 0;
            else
                s->m230 ^= 1;
        }
    }
    return true;
}
