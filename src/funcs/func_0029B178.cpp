struct Snd_0029B178 {
    char pad[0x14];
    int playing;
    bool IsPlaying() { return playing != 0; }
    char pad2[0x24 - 0x18];
};

struct Inner_0029B178 {
    char pad[0x190];
    Snd_0029B178 snd[4];
};

extern "C" void func_0026FDC8(Snd_0029B178* s);
extern "C" void func_001F0210(unsigned int name, void* params, void* obj, int a, int b);

struct Obj_0029B178 {
    char pad[0xC];
    void* m0C;
    char pad2[0x1C - 0x10];
    Inner_0029B178* m1C;
    void Stop();
};

void Obj_0029B178::Stop()
{
    Inner_0029B178* p = m1C;
    if (p->snd[3].IsPlaying()) {
        func_0026FDC8(&p->snd[3]);
        func_001F0210(0x415F2AFA, 0, m0C, 0, 0);
    }
    if (p->snd[2].IsPlaying()) {
        func_0026FDC8(&p->snd[2]);
        func_001F0210(0x3AD21C4E, 0, m0C, 0, 0);
    }
    if (p->snd[1].IsPlaying()) {
        func_0026FDC8(&p->snd[1]);
        func_001F0210(0xD8D956C9, 0, m0C, 0, 0);
    }
    if (p->snd[0].IsPlaying()) {
        func_0026FDC8(&p->snd[0]);
        func_001F0210(0xC18D5B19, 0, m0C, 0, 0);
    }
    func_001F0210(0x97153F0E, 0, m0C, 0, 0);
}
