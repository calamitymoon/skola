class AgregaceData {
  final double prumernaTeplota;
  final double prumernaVlhkost;
  final double prumerneCo2;
  final double prumernyTlak;

  AgregaceData({
    required this.prumernaTeplota,
    required this.prumernaVlhkost,
    required this.prumerneCo2,
    required this.prumernyTlak,
  });

  factory AgregaceData.fromJson(Map<String, dynamic> json) {
    return AgregaceData(
      prumernaTeplota: json['prumerna_teplota']?.toDouble() ?? 0.0,
      prumernaVlhkost: json['prumerna_vlhkost']?.toDouble() ?? 0.0,
      prumerneCo2: json['prumerne_co2']?.toDouble() ?? 0.0,
      prumernyTlak: json['prumerny_tlak']?.toDouble() ?? 0.0,
    );
  }
}