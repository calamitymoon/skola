import 'package:flutter/material.dart';
import '../services/api_service.dart';
import '../models/alarm.dart';

class AlarmScreen extends StatefulWidget {
  final String? userToken; // Added to check authentication status

  const AlarmScreen({Key? key, this.userToken}) : super(key: key);

  @override
  _AlarmScreenState createState() => _AlarmScreenState();
}

class _AlarmScreenState extends State<AlarmScreen> {
  Future<AlarmState>? _alarmState;
  final ApiService _apiService = ApiService();

  // New variables for alarm management
  final List<Map<String, dynamic>> _alarmCodes = [
    {'code': 0, 'description': 'Žádný alarm'},
    {'code': 100, 'description': 'Poplach'},
    {'code': 200, 'description': 'Požár'},
    {'code': 300, 'description': 'Evakuace'},
    {'code': 400, 'description': 'Únik plynu'},
    {'code': 500, 'description': 'Chemická hrozba'},
    {'code': 600, 'description': 'Střelec v budově'}
  ];

  // Device list from API
  List<int> _availableDevices = [1, 2, 3, 4, 5]; // Placeholder, fetch from API
  int? _selectedDeviceId;
  int? _selectedAlarmCode;

  @override
  void initState() {
    super.initState();
    // Fetch available devices when screen initializes
    _fetchAvailableDevices();
  }

  Future<void> _fetchAvailableDevices() async {
    try {
      // Fetch devices from API
      final devices = await _apiService.fetchLimitedDevices();
      setState(() {
        _availableDevices = devices.map((device) => device.id_pristroje!).toList();
      });
    } catch (e) {
      ScaffoldMessenger.of(context).showSnackBar(
        SnackBar(content: Text('Chyba při načítání přístrojů: $e')),
      );
    }
  }

  void _showAlarmManagementDialog() {
    showDialog(
      context: context,
      builder: (BuildContext context) {
        return StatefulBuilder(
          builder: (context, setState) {
            return AlertDialog(
              title: Text('Správa alarmů'),
              content: Column(
                mainAxisSize: MainAxisSize.min,
                children: [
                  DropdownButton<int>(
                    hint: Text('Vyberte přístroj'),
                    value: _selectedDeviceId,
                    items: _availableDevices
                        .map((id) => DropdownMenuItem<int>(
                      value: id,
                      child: Text('Přístroj $id'),
                    ))
                        .toList(),
                    onChanged: (value) {
                      setState(() {
                        _selectedDeviceId = value;
                        // Fetch alarm state for selected device
                        if (value != null) {
                          _alarmState = _apiService.fetchAlarmState(value);
                        }
                      });
                    },
                  ),
                  DropdownButton<int>(
                    hint: Text('Vyberte typ alarmu'),
                    value: _selectedAlarmCode,
                    items: _alarmCodes
                        .map((alarm) => DropdownMenuItem<int>(
                      value: alarm['code'],
                      child: Text(alarm['description']),
                    ))
                        .toList(),
                    onChanged: (value) {
                      setState(() {
                        _selectedAlarmCode = value;
                      });
                    },
                  ),
                ],
              ),
              actions: [
                TextButton(
                  child: Text('Přidat alarm'),
                  onPressed: _addAlarm,
                ),
                TextButton(
                  child: Text('Odebrat alarm'),
                  onPressed: _removeAlarm,
                ),
              ],
            );
          },
        );
      },
    );
  }

  void _addAlarm() async {
    if (_selectedDeviceId == null || _selectedAlarmCode == null) {
      ScaffoldMessenger.of(context).showSnackBar(
        SnackBar(content: Text('Vyberte přístroj a typ alarmu')),
      );
      return;
    }

    try {
      await _apiService.addAlarm(_selectedDeviceId!, _selectedAlarmCode!);

      ScaffoldMessenger.of(context).showSnackBar(
        SnackBar(content: Text('Alarm byl přidán')),
      );
      Navigator.of(context).pop();

      // Refresh alarm state
      setState(() {
        _alarmState = _apiService.fetchAlarmState(_selectedDeviceId!);
      });
    } catch (e) {
      ScaffoldMessenger.of(context).showSnackBar(
        SnackBar(content: Text('Chyba při přidávání alarmu: $e')),
      );
    }
  }

  void _removeAlarm() async {
    if (_selectedDeviceId == null) {
      ScaffoldMessenger.of(context).showSnackBar(
        SnackBar(content: Text('Vyberte přístroj')),
      );
      return;
    }

    try {
      await _apiService.removeAlarm(_selectedDeviceId!);

      ScaffoldMessenger.of(context).showSnackBar(
        SnackBar(content: Text('Alarm byl odebrán')),
      );
      Navigator.of(context).pop();

      // Refresh alarm state
      setState(() {
        _alarmState = _apiService.fetchAlarmState(_selectedDeviceId!);
      });
    } catch (e) {
      ScaffoldMessenger.of(context).showSnackBar(
        SnackBar(content: Text('Chyba při odebírání alarmu: $e')),
      );
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Správa alarmů'),
      ),
      body: Column(
        children: [
          // Device selector
          Padding(
            padding: const EdgeInsets.all(16.0),
            child: DropdownButton<int>(
              hint: Text('Vyberte přístroj'),
              value: _selectedDeviceId,
              items: _availableDevices
                  .map((id) => DropdownMenuItem<int>(
                value: id,
                child: Text('Přístroj $id'),
              ))
                  .toList(),
              onChanged: (value) {
                setState(() {
                  _selectedDeviceId = value;
                  if (value != null) {
                    _alarmState = _apiService.fetchAlarmState(value);
                  }
                });
              },
            ),
          ),

          // Alarm state display
          if (_selectedDeviceId != null)
            FutureBuilder<AlarmState>(
              future: _alarmState,
              builder: (context, snapshot) {
                if (snapshot.connectionState == ConnectionState.waiting) {
                  return CircularProgressIndicator();
                } else if (snapshot.hasError) {
                  return Text('Chyba: ${snapshot.error}');
                } else if (!snapshot.hasData) {
                  return Text('Žádná data');
                }

                final alarmState = snapshot.data!;
                return Column(
                  children: [
                    Text(
                      'Stav alarmu: ${alarmState.description}',
                      style: TextStyle(
                        fontSize: 24,
                        color: alarmState.code == 0 ? Colors.green : Colors.red,
                      ),
                    ),
                  ],
                );
              },
            ),

          // Only show management buttons if user is authenticated
          if (widget.userToken != null)
            ElevatedButton(
              onPressed: _showAlarmManagementDialog,
              child: Text('Spravovat alarmy'),
            ),
        ],
      ),
    );
  }
}