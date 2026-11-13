/* fuzzy: 92.5 */
extern int D_003940A0;   /* current time */

struct ColorKey_00171EB0 {
    int time;
    float r, g, b, a;
};

struct Obj_00171EB0 {
    char pad[0x38];
    int* m_colorAnims;
    void UpdateColors();
};

/* m_colorAnims: count, then per animation (anim = { numKeys, timeOffset, ColorKey keys[] }) { anim*, numTargets, unsigned int* target[numTargets] } */
void Obj_00171EB0::UpdateColors()
{
    int* p = m_colorAnims;
    int count = *p++;
    for (int i = 0; i < count; i++) {
        int* q = (int*)*p++;
        int n = *q++;
        int offset = *q++;
        ColorKey_00171EB0* keys = (ColorKey_00171EB0*)q;
        int last = n - 1;
        ColorKey_00171EB0* key = keys + n - 1;
        int start = keys[0].time;
        int end = key->time;
        int t = start + (D_003940A0 + offset) % (end - start);
        if (t < start)
            t = start;
        if (end < t)
            t = end;
        int k = last;
        while (k >= 0 && t < key->time) {
            k--;
            key--;
        }
        float f = (float)(t - key->time) / (float)(key[1].time - key->time);
        float g = 1.0f - f;
        int r = (int)(g * key->r + f * key[1].r);
        int gr = (int)(g * key->g + f * key[1].g);
        int b = (int)(g * key->b + f * key[1].b);
        int a = (int)(g * key->a + f * key[1].a);
        unsigned int color = (r & 0xFF) | ((gr << 8) & 0xFF00) | ((b << 16) & 0xFF0000) | (a << 24);
        int numTargets = *p++;
        for (int j = 0; j < numTargets; j++) {
            *(unsigned int*)*p++ = color;
        }
    }
}
