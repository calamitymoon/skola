class AlarmState {
  static const Map<int, String> alarmCodes = {
    0: 'Žádný alarm',
    100: 'Poplach',
    200: 'Požár',
    300: 'Evakuace',
    400: 'Únik plynu',
    500: 'Chemická hrozba',
    600: 'Střelec v budově'
  };

  final int code;
  final String description;

  AlarmState({
    required this.code,
    required this.description,
  });

  factory AlarmState.fromCode(int code) {
    return AlarmState(
      code: code,
      description: alarmCodes[code] ?? 'Neznámý alarm',
    );
  }
}