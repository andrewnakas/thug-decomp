struct Sprite_0020E968 {
    float m_scaleX;
    float m_scaleY;
    char m_pad[0x18];
};

extern char D_0038F3B0[];
extern char D_0038F3B8[];

extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E7F50(void* params, const char* name, float* out, int required);
extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int required);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" bool func_001E1348(unsigned int id);
extern "C" void func_001DC560(Sprite_0020E968* sprite, int a);
extern "C" void func_001DC578(Sprite_0020E968* sprite, int flags);
extern "C" void func_001DF740(unsigned int id, Sprite_0020E968* sprite, int a, unsigned int b, int c, float d);

bool func_0020E968(void* params)
{
    unsigned int id = 0;
    if (!func_001E8398(params, 0, &id, 0)) {
        return false;
    }
    float scale_x;
    float scale_y;
    float scale;
    float alpha;
    scale = 100.0f;
    scale_x = 100.0f;
    scale_y = 100.0f;
    alpha = 100.0f;
    int time = 0x32;
    unsigned int anim = 0;
    int check = 0;
    func_001E7F50(params, D_0038F3B0, &scale_x, 0);
    func_001E7F50(params, D_0038F3B8, &scale_y, 0);
    if (func_001E7EB0(params, 0xF6A36814, &scale, 0)) {
        scale_x = scale;
        scale_y = scale;
    }
    func_001E7EB0(params, 0xD8604126, &alpha, 0);
    func_001E7DE8(params, 0x9D5923D8, &time, 0);
    func_001E8398(params, 0x40C698AF, &anim, 0);
    func_001E7DE8(params, 0xF5C3922B, &check, 0);
    if (check != 1 || func_001E1348(id)) {
    Sprite_0020E968 sprite;
    func_001DC560(&sprite, 0);
    sprite.m_scaleX = scale_x;
    sprite.m_scaleY = scale_y;
    func_001DF740(id, &sprite, time, anim, 1, alpha);
    func_001DC578(&sprite, 2);
    return true;
    }
    return false;
}
