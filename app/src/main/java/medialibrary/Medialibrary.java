package medialibrary;

import android.view.SurfaceHolder;

public class Medialibrary {
    static {
        System.loadLibrary("playerLib");
    }
    public static native int nativeInit(String url);
    public static native int nativeSetSurface(SurfaceHolder surfaceHolder);
    public static native int nativePlay();
    public static native int nativeStop();
}
