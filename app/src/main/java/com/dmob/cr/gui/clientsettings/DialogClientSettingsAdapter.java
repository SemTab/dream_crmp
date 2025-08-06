package com.dmob.cr.gui.clientsettings;

import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentManager;
import androidx.fragment.app.FragmentPagerAdapter;
import java.util.ArrayList;
import java.util.List;

public class DialogClientSettingsAdapter extends FragmentPagerAdapter {
    List<Fragment> mFragmentCollection = new ArrayList();
    List<String> mTitleCollection = new ArrayList();

    public DialogClientSettingsAdapter(FragmentManager fragmentManager, int i) {
        super(fragmentManager, i);
    }

    public void addFragment(String str, Fragment fragment) {
        this.mTitleCollection.add(str);
        this.mFragmentCollection.add(fragment);
    }

    public CharSequence getPageTitle(int i) {
        return this.mTitleCollection.get(i);
    }

    public Fragment getItem(int i) {
        return this.mFragmentCollection.get(i);
    }

    public int getCount() {
        return this.mFragmentCollection.size();
    }
}
