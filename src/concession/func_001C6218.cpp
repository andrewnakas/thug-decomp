/* force: {"kind": "fr", "reg": 118, "hard": 35} */
struct Skater_001C6218 {
    char pad0[0xB0];
    float mB0;
    char padB4[0xA60 - 0xB4];
    int mA60;
    char padA64[0xB54 - 0xA64];
    float mB54;
};

extern "C" void* func_001E5548(unsigned int, int);
extern "C" bool func_001E7EB0(void*, unsigned int, float*, int);

static inline float GetPhysics_001C6218(unsigned int name)
{
    float v;
    func_001E7EB0(func_001E5548(0x6775E538, 0), name, &v, 1);
    return v;
}

float func_001C6218(Skater_001C6218* sk)
{
    if (sk->mB0 != 0.0f) {
        float limit = GetPhysics_001C6218(0xC1528F7F);
        if (sk->mB0 <= limit) {
            sk->mA60 = 0;
            return GetPhysics_001C6218(0x79D182AD) * ((sk->mB0 - 0.3f) / (limit - 0.3f));
        } else {
            sk->mA60 = 1;
            float lo = GetPhysics_001C6218(0x79D182AD);
            float mid = GetPhysics_001C6218(0xCC461B87);
            float hi = GetPhysics_001C6218(0x7213EF07);
            return lo + ((mid + (hi - mid) * sk->mB54) - lo) * ((sk->mB0 - limit) / (1.0f - limit));
        }
    }
    return 0.0f;
}
