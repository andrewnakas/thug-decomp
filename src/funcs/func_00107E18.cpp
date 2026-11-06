extern "C" void func_00107E10(void* self);
extern "C" void func_00107D80(void* self);

struct Snd_00107E18 {
    char pad0[0xC8];
    int mC8;
    void Refresh();
};

void Snd_00107E18::Refresh()
{
    if (mC8) {
        func_00107E10(this);
        func_00107D80(this);
    } else {
        func_00107D80(this);
        func_00107E10(this);
    }
}
