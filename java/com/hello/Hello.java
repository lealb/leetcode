package com.hello;

class Hello {
    /**
     * 调试java带有package的时候直接使用java +class会有问题
     * @param args
     */
    public static void main(String[] args) {
        int i = 1;
        System.out.println(i + 1);
        System.out.println("Hello");
    }
}