package com.EpiPay;

import android.content.Intent;
import android.os.Bundle;
import android.app.Activity;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ListView;

public class MenuActivity extends Activity {
    private ListView listView1;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_menu);

        Menu_list menu_data[] = new Menu_list[]
                {
                        new Menu_list(R.drawable.stock, "Gestionnaire"),
                        new Menu_list(R.drawable.money, "Paiement")
                };

        MenuAdapter adapter = new MenuAdapter(this, R.layout.listivew_item_rw, menu_data);

        listView1 = (ListView) findViewById(R.id.listView1);

        View header = (View) getLayoutInflater().inflate(R.layout.listview_header_row, null);
        listView1.addHeaderView(header);

        listView1.setAdapter(adapter);
        listView1.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            public void onItemClick(AdapterView<?> parent, View view,
                                    int position, long id) {
                if (position == 1) {
                    Intent myIntent = new Intent(view.getContext(), Gestion.class);
                    startActivityForResult(myIntent, 0);
                }

                if (position == 2) {
                    Intent myIntent = new Intent(view.getContext(), ScanActivity.class);
                    startActivityForResult(myIntent, 0);
                }
            }
        });
    }
}