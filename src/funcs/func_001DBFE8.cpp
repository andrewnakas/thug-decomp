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
extern "C" void* func_001DBBB8(Probe_001DC0A8* probe, void* name, float t);
extern "C" int func_001DBCB0(void* node, void* out);

int func_001DBFE8(void* out, void* self, void* name, float t)
{
    int result = 0;
    if (func_001DC418())
        return 0;
    Probe_001DC0A8* probe = new Probe_001DC0A8;
    if (func_001DB860(self, probe)) {
        void* node = func_001DBBB8(probe, name, t);
        if (node)
            result = func_001DBCB0(node, out);
    }
    delete probe;
    return result;
}
