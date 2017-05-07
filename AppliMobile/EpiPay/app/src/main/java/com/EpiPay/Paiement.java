package com.EpiPay;

import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.widget.TextView;

public class Paiement extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_paiement);
        Intent intent = getIntent();
        String result = intent.getStringExtra("result");
        TextView resultPrice = (TextView) findViewById(R.id.ResultPrice);
        resultPrice.setText(result);
    }
}
