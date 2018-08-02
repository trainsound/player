package com.morning.trainsound.player;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.Surface;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.view.View;
import android.widget.Button;

import medialibrary.Medialibrary;

public class MainActivity extends AppCompatActivity implements SurfaceHolder.Callback {
    private Button start, stop;
    private SurfaceView surface;
    private Medialibrary medialibrary;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        start = (Button)findViewById(R.id.btnStart);
        stop = (Button)findViewById(R.id.btnStop);
        surface = (SurfaceView)findViewById(R.id.surfaceID);
        medialibrary = new Medialibrary();

        start.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                medialibrary.nativeSetDataSource("test url");
            }
        });

        stop.setOnClickListener(new View.OnClickListener(){

            @Override
            public void onClick(View v) {
                medialibrary.nativeStop();
            }
        });
    }

    @Override
    public void surfaceCreated(SurfaceHolder holder) {

    }

    @Override
    public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) {

    }

    @Override
    public void surfaceDestroyed(SurfaceHolder holder) {

    }
}
