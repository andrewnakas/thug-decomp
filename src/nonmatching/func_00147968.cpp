/* fuzzy: 66.9 */
extern "C" void* func_00331404(void* dst, const void* src, unsigned int n);

extern "C" void func_00147968(unsigned char* img, unsigned short x, unsigned short y, unsigned short imgW,
                              unsigned short imgH, unsigned char* buf, unsigned short w, unsigned short h,
                              unsigned short bpp)
{
    int cw = imgW - x;
    int ch = imgH - y;
    int bytes = bpp >> 3;
    int rowBytes, srcPitch, dstPitch;
    int rows;
    cw = (cw < w) ? cw : w;
    rows = (ch < h) ? ch : h;
    if (bytes) {
        dstPitch = imgW * bytes;
        rowBytes = cw * bytes;
        srcPitch = w * bytes;
        img += (y * imgW + x) * bytes;
    } else {
        srcPitch = w / 2;
        dstPitch = imgW / 2;
        rowBytes = cw / 2;
        img += (y * imgW + x) / 2;
    }
    for (int i = 0; i < rows; i++) {
        func_00331404(img, buf, rowBytes);
        buf += srcPitch;
        img += dstPitch;
    }
}
