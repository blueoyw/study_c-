#include <iostream>
:q

public class CoinChange {

	private int ten;
	private int fifty;
	private int hundred;
	private int fiveHundred;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		CoinChange cc = new CoinChange();

		System.out.print("거스름돈을 입력하세요 : ");
		int change = sc.nextInt();

		while(change >= 500) {
			change -= 500;
			cc.fiveHundred++;
		}
		while(change >= 100) {
			change -= 100;
			cc.hundred++;
		}
		while(change >= 50) {
			change -= 50;
			cc.fifty++;
		}
		while(change >= 10) {
			change -= 10;
			cc.ten++;
		}

		System.out.println("10원짜리 " + cc.ten + "개");
		System.out.println("50원짜리 " + cc.fifty + "개");
		System.out.println("100원짜리 " + cc.hundred + "개");
		System.out.println("500원짜리 " + cc.fiveHundred + "개");
		System.out.println("총 동전 개수는 " + (cc.ten + cc.fifty + cc.hundred + cc.fiveHundred) + "개 입니다.");
	}
}
