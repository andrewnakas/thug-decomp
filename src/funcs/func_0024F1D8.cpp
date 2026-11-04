struct Mode_0024F1D8 {
    int m0;
    char m4[1];
};

extern "C" unsigned int func_0024F938(Mode_0024F1D8* self);
extern "C" bool func_001E88D8(void* self, unsigned int name, int* out, int assert_);

bool func_0024F1D8(Mode_0024F1D8* self)
{
    int value;

    if (func_0024F938(self) == 0x5D32129C || func_0024F938(self) == 0x6EF8FDA0 || func_0024F938(self) == 0xF135ECB6
        || func_0024F938(self) == 0x1498240A || func_0024F938(self) == 0xE45F0CA2 || func_0024F938(self) == 0x3D6D444F
        || func_0024F938(self) == 0xBFF33600)
        return false;
    func_001E88D8(self->m4, 0x8D38A280, &value, 1);
    return value != 0;
}
