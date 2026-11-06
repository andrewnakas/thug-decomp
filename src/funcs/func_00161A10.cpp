extern "C" void* func_00331404(void* dst, const void* src, int n);

void Copy_00161A10(unsigned short* src, void* dst)
{
    func_00331404(dst, src, (*src + 1) * 16);
}
