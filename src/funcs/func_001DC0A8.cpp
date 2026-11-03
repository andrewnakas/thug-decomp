extern "C" void* func_001190D0(int size);
extern "C" bool func_001DC418();

struct Probe_001DC0A8 {
    int m0;
    int m4;
    Probe_001DC0A8();
    ~Probe_001DC0A8();
    static void* operator new(unsigned int size) { return func_001190D0(size); }
};

extern "C" bool func_001DB860(void* self, Probe_001DC0A8* probe);
extern "C" void func_001DBEA8(Probe_001DC0A8* probe, int slot);

bool func_001DC0A8(void* self)
{
    if (func_001DC418()) {
        return false;
    }
    Probe_001DC0A8* probe = new Probe_001DC0A8;
    if (func_001DB860(self, probe)) {
        for (int i = 0; i < 11; i++) {
            func_001DBEA8(probe, i);
        }
    }
    delete probe;
    return true;
}
