/* fuzzy: 84.3 */
struct Sprite_0020F010 {
    float m_scaleX;
    float m_scaleY;
    char m_pad[0x18];
};

extern void* D_0038E0A0;

extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int required);
extern "C" void func_001DC540(Sprite_0020F010* sprite);
extern "C" void func_001DC6D0(Sprite_0020F010* sprite);
extern "C" void func_001DC578(Sprite_0020F010* sprite, int flags);
extern "C" void func_001DD4A8(void* screen, unsigned int id, Sprite_0020F010* sprite, float alpha);

bool func_0020F010(void* params)
{
    unsigned int id = 0;
    if (func_001E8398(params, 0, &id, 0)) {
        float scale_x;
        float scale_y;
        float scale;
        float alpha;
        scale_x = 100.0f;
        scale_y = 100.0f;
        alpha = 100.0f;
        func_001E7EB0(params, 0x5E285A66, &scale_x, 0);
        func_001E7EB0(params, 0xA4276705, &scale_y, 0);
        if (func_001E7EB0(params, 0xF6A36814, &scale, 0)) {
            scale_x = scale;
            scale_y = scale;
        }
        func_001E7EB0(params, 0xD8604126, &alpha, 0);
        Sprite_0020F010 sprite;
        func_001DC540(&sprite);
        func_001DC6D0(&sprite);
        sprite.m_scaleX = scale_x;
        sprite.m_scaleY = scale_y;
        func_001DD4A8(D_0038E0A0, id, &sprite, alpha);
        func_001DC578(&sprite, 2);
    }
    return true;
}
