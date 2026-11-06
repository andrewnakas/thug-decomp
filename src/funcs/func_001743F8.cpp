/* static initialisation for a translation unit: constructs a 4-element array whose constructor is empty */
extern "C" void func_001743F8(int initialize, int priority)
{
    if (priority == 0xFFFF && initialize) {
        for (int n = 3; n != -1; n--)
            ;
    }
}
