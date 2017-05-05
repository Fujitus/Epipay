package com.EpiPay;

import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.ListView;
import android.widget.Spinner;
import android.widget.TextView;
import android.widget.Toast;
import java.util.ArrayList;
import com.google.zxing.integration.android.IntentIntegrator;
import com.google.zxing.integration.android.IntentResult;

public class ScanActivity extends AppCompatActivity implements OnClickListener {
    private Button scanBtn;
    private TextView tvScanFormat, tvScanContent, ResultPrice;
    private LinearLayout llSearch;
    ArrayList<Product> products = new ArrayList<Product>();
    ProductAdapter boxAdapter;
    String aff_result;
    ListView lvMain;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_scan);
        scanBtn = (Button) findViewById(R.id.scan_button);
        tvScanFormat = (TextView) findViewById(R.id.tvScanFormat);
        tvScanContent = (TextView) findViewById(R.id.tvScanContent);
        llSearch = (LinearLayout) findViewById(R.id.llSearch);
        ResultPrice = (TextView) findViewById(R.id.ResultPrice);
        fillData();
        aff_result = "Total Price : 0";
        boxAdapter = new ProductAdapter(this, products);
        lvMain = (ListView) findViewById(R.id.lvMain);
        lvMain.setAdapter(boxAdapter);
        scanBtn.setOnClickListener(this);
    }

    void prix(View V)
    {
        double income;

        income = 0;
        for (Product p : boxAdapter.getBox()) {
            double mult = 0;
            if (p.box) {
                if (p.spinner.getPositionForView(V)== 1)
                    mult = 1;
                if (p.spinner.getPositionForView(V)== 2)
                    mult = 2;
                income += p.price * mult;
            }
        }
        if (income != 0) {
            aff_result = "Prix : ";
            aff_result += Double.toString(income);
        }
        Intent intent = new Intent(V.getContext(), Paiement.class);
        intent.putExtra("result", aff_result);
        startActivityForResult(intent, 0);
    }

    void delete_data()
    {
        for (Product p : boxAdapter.getBox()) {
            if (p.box) {
                products.remove(p);
                boxAdapter.notifyDataSetChanged();
            }
        }
    }

    void fillData() {
        products.add(new Product("Café :", null, 0.35, R.drawable.cafe, false));
        products.add(new Product("Madelaine :", null, 0.10, R.drawable.madelaine, false));
        products.add(new Product("Spéculoos :", null, 0.10, R.drawable.speculoos, false));
    }

    public void onClick(View v)
    {
        llSearch.setVisibility(View.GONE);
        IntentIntegrator integrator = new IntentIntegrator(this);
        integrator.setPrompt("Scan a barcode");
        integrator.setOrientationLocked(false);
        integrator.initiateScan();
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        IntentResult result = IntentIntegrator.parseActivityResult(requestCode, resultCode, data);
        if (result != null) {
            if (result.getContents() == null) {
                llSearch.setVisibility(View.GONE);
                Toast.makeText(this, "Cancelled", Toast.LENGTH_LONG).show();
            } else {
                llSearch.setVisibility(View.VISIBLE);
                tvScanContent.setText(result.getContents());
                tvScanFormat.setText(result.getFormatName());
            }
        } else {
            super.onActivityResult(requestCode, resultCode, data);
        }
    }
}