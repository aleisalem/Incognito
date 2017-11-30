package com.tum.incognito;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.content.Context;
import android.os.AsyncTask;
import android.util.Log;
import android.view.View;
import android.widget.EditText;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.Toast;
import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;

public class MainActivity extends AppCompatActivity {


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void processInput(View view){
        // Process user input
        EditText inputText = (EditText) findViewById(R.id.Txt_Main_Input);
        RadioGroup mode = (RadioGroup) findViewById(R.id.RGp_Main_Options);
        RadioButton selectedMode = (RadioButton) findViewById(mode.getCheckedRadioButtonId());
        String url = getURL(selectedMode.getText().toString());
        new MyRequestTask(getApplicationContext()).execute(inputText.getText().toString(), selectedMode.getText().toString(), url);
    }

    public native String getURL(String s);

    static {
        System.loadLibrary("secret-keeper");
    }

}

class MyRequestTask extends AsyncTask<String, Void, String> {

    private Context context;
    public static String output = "";

    MyRequestTask(Context context) {
        this.context = context;
    }

    @Override
    protected String doInBackground(String... args) {
        String input = args[0];
        String mode = args[1];
        String url = args[2];

        if (mode.equals("MODE1")) {
            // HTTP request for weather forecast
            try {
                Log.d("Incognito", "Input: " + input + ", mode: " + mode);
                URL http = new URL(url + input);
                HttpURLConnection urlConnection = (HttpURLConnection) http.openConnection();
                BufferedInputStream in = new BufferedInputStream(urlConnection.getInputStream());
                output = processResponse(in, mode);
                urlConnection.disconnect();
            } catch (IOException e) {
                Log.d("Incognito", "Unable to open connection");
            }
        } else if (mode.equals("MODE2")) {
            // HTTP request for restaurants nearby
            try {
                Log.d("Incognito", "Input: " + input + ", mode: " + mode);
                URL http = new URL(url + input);
                HttpURLConnection urlConnection = (HttpURLConnection) http.openConnection();
                InputStream in = new BufferedInputStream(urlConnection.getInputStream());
                output = processResponse(in, mode);
                urlConnection.disconnect();
            } catch (IOException e) {
                Log.d("Incognito", "Unable to open connection");
            }
        } else
            throw new UnsupportedOperationException("Invalid mode");

        return output;
    }

    @Override
    protected void onPreExecute() {
        Toast.makeText(this.context, "Incognito says: processing request", Toast.LENGTH_LONG).show();
    }

    @Override
    protected void onPostExecute(String result) {
        Toast.makeText(this.context, "Incognito says: " + output, Toast.LENGTH_LONG).show();
    }

    public String processResponse(InputStream response, Object mode) {
        String output = "Nix!!";
        String content = "";
        StringBuilder sb = new StringBuilder();
        BufferedReader br = new BufferedReader(new InputStreamReader(response));
        String tempLine;
        String keyword = "";
        // Read all content from the response
        try {
            while ((tempLine = br.readLine()) != null)
                sb.append(tempLine);
            // Convert to string
            content = sb.toString();
        } catch (IOException e) {
            Log.d("Incognito", "Error encountered while reading response from MODE1");
        }
        if (mode.equals("MODE1")) {
            // MODE 1
            keyword = "text--white beta palm-hide";
            int index = content.indexOf(keyword);
            if (index != -1)
                output = content.substring(index+keyword.length()+2, index+keyword.length()+6);
        } else if (mode.equals("MODE2")) {
            // MODE 2
            keyword = "lang=\"de\"><samp>";
            int stIndex = content.indexOf(keyword);
            int endIndex = content.indexOf("<a", stIndex);
            if ((stIndex != -1) && (endIndex != -1))
                output = content.substring(stIndex + keyword.length(), endIndex);
        }
        return output;
    }
}
