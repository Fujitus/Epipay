package com.EpiPay;


import android.widget.Spinner;

public class Product {
    String name;
    Spinner spinner;
    double price;
    int image;
    boolean box;


    Product(String _describe, Spinner _spinner, double _price, int _image, boolean _box) {
        name = _describe;
        price = _price;
        spinner = _spinner;
        image = _image;
        box = _box;
    }
}