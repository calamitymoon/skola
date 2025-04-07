class MerakDevice {
  final int? id_pristroje;
  final dynamic teplota;
  final dynamic vlhkost;
  final dynamic co2;
  final dynamic tlak;
  final dynamic cas;

  MerakDevice({
    this.id_pristroje,
    this.teplota,
    this.vlhkost,
    this.co2,
    this.tlak,
    this.cas,
  });

  factory MerakDevice.fromJson(Map<String, dynamic> json) {
    return MerakDevice(
      id_pristroje: json['id_pristroje'],
      teplota: json['teplota'],
      vlhkost: json['vlhkost'],
      co2: json['co2'],
      tlak: json['tlak'],
      cas: json['cas'],
    );
  }
}