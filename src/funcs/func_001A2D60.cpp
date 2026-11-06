/* Static-init: three blocks at D_003E6280 and one at D_003E7A80, each 64 quaternions (identity w = 1)
   followed by 64 16-byte entries whose constructor is empty. */
struct Quat_001A2D60 {
    float x, y, z, w;
    Quat_001A2D60() { x = 0.0f; y = 0.0f; z = 0.0f; w = 1.0f; }
};

struct Pad_001A2D60 {
    float v[4];
    Pad_001A2D60() {}
};

struct Block_001A2D60 {
    Quat_001A2D60 m_rot[64];
    Pad_001A2D60 m_pad[64];
};

extern Block_001A2D60 D_003E6280[3];
extern Block_001A2D60 D_003E7A80;

inline void* operator new(unsigned int, void* p) { return p; }

void func_001A2D60(int initialize, int priority)
{
    if (priority == 0xFFFF && initialize) {
        Block_001A2D60* p = D_003E6280;
        for (int i = 2; i != -1; i--) {
            new (p) Block_001A2D60;
            p++;
        }
        new (&D_003E7A80) Block_001A2D60;
    }
}
