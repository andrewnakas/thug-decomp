struct Snd_0014C4D8;
extern "C" void func_00170600(Snd_0014C4D8* s, int a);
extern "C" void func_00170758(Snd_0014C4D8* s, int v);

struct Scrn_0014C4D8 {
    char pad[0x290];
    Snd_0014C4D8* m290;
    Snd_0014C4D8* m294;
    void Apply(int* v);
};

void Scrn_0014C4D8::Apply(int* v)
{
    if (m290) {
        func_00170600(m290, 1);
        func_00170758(m290, *v);
    }
    if (m294) {
        func_00170600(m294, 1);
        func_00170758(m294, *v);
    }
}
