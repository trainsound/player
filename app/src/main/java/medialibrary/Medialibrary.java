package medialibrary;

import android.view.SurfaceHolder;

public class Medialibrary {
    static {
        System.loadLibrary("playerLib");
    }

    public native int nativeSetDataSource(String url);
    public native int nativePlay();
    public native int nativeStop();
}
