/* fuzzy: 82.3 */
/* blocked: game keeps mE0 in $t0 on the mask-miss path (PRE'd reload only after the store); tried continue/&&/early return/while/entry ref/unsigned types/Count() inline: always reloads on both paths. */
struct Ent_0014CFC0 {
    int m0;
    unsigned short* m4;
};

class Snd_0014CFC0 {
public:
    char pad[0xC0];
    unsigned long mC0 : 32;
    bool mFlag0 : 1;
    unsigned long mFlag1 : 1;
    void* mC8;
    char mCC[0x10];
    Ent_0014CFC0* mDC;
    int mE0;
    void Hide(int mask);
};

void Snd_0014CFC0::Hide(int mask)
{
    if (!mFlag0) {
        for (int i = 0; i < mE0; i++) {
            if (mDC[i].m0 & mask) {
                if (mDC[i].m4) *mDC[i].m4 = 0xC000;
            }
        }
        mFlag0 = 1;
    }
}
