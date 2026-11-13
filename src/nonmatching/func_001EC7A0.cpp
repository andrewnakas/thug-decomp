/* fuzzy: 90.0 */
// nm: 3 words: or operand order b0|(b1<<8) (writing b0 first makes gcc copy p to a2, size 0x40)
extern "C" unsigned int func_001EC7A0(const unsigned char* p)
{
    if ((unsigned int)p & 3)
        return (p[1] << 8) | p[0] | (p[2] << 16) | (p[3] << 24);
    return *(unsigned int*)p;
}
