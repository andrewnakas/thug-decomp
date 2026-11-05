extern "C" void func_00268A40(void* self);

struct Cfg_00269038 {
    char pad[0xAC];
    unsigned int mAC;
};

extern Cfg_00269038* D_00392808;

void Update_00269038(void* self)
{
    if (D_00392808->mAC != 0xD443A2BC)
        func_00268A40(self);
}
