import 'package:http/http.dart' as http;
import 'dart:convert';
import '../models/measuring_device.dart';
import '../models/user.dart';
import '../models/alarm.dart';
import '../models/agregace.dart';

class ApiService {
  static const String baseUrl = 'https://uplne.cokoliv.eu/kyslik-api/api/v1';
  String? _authToken;

  // User Login
  Future<User> loginUser(String jmeno, String heslo) async {
    final response = await http.post(
      Uri.parse('$baseUrl/uzivatele/login'),
      body: json.encode({
        'jmeno': jmeno,
        'heslo': heslo,
      }),
      headers: {'Content-Type': 'application/json'},
    );

    if (response.statusCode == 200) {
      final user = User.fromJson(json.decode(response.body));
      _authToken = user.token; // Ensure this line is present
      print('Token received: $_authToken'); // Optional: log the token
      return user;
    } else {
      throw Exception(json.decode(response.body)['error'] ?? 'Login failed');
    }
  }

  // User Registration
  Future<void> registerUser(String jmeno, String heslo) async {
    final response = await http.post(
      Uri.parse('$baseUrl/uzivatele/register'),
      body: json.encode({
        'jmeno': jmeno,
        'heslo': heslo,
      }),
      headers: {'Content-Type': 'application/json'},
    );

    if (response.statusCode != 200) {
      throw Exception(json.decode(response.body)['error'] ?? 'Registration failed');
    }
  }

  // List Users (requires authentication)
  Future<List<dynamic>> listUsers() async {
    final response = await http.get(
      Uri.parse('$baseUrl/uzivatele/list'),
      headers: {
        'Authorization': 'Bearer $_authToken',
        'Content-Type': 'application/json'
      },
    );

    if (response.statusCode == 200) {
      return json.decode(response.body);
    } else {
      throw Exception('Failed to load users');
    }
  }

  // Measuring Devices - Limited List
  Future<List<MerakDevice>> fetchLimitedDevices() async {
    final response = await http.get(Uri.parse('$baseUrl/merak/limited'));

    if (response.statusCode == 200) {
      List jsonResponse = json.decode(response.body);
      return jsonResponse.map((device) => MerakDevice.fromJson(device)).toList();
    } else {
      throw Exception(json.decode(response.body)['error'] ?? 'Failed to load limited devices');
    }
  }

  // Measuring Device by ID (Limited)
  Future<List<MerakDevice>> fetchDeviceById(int id) async {
    final response = await http.get(Uri.parse('$baseUrl/merak/limited/id/$id'));

    if (response.statusCode == 200) {
      List jsonResponse = json.decode(response.body);
      return jsonResponse.map((device) => MerakDevice.fromJson(device)).toList();
    } else {
      throw Exception(json.decode(response.body)['error'] ?? 'Failed to load device details');
    }
  }

  // Full Device List (requires authentication)
  Future<List<MerakDevice>> fetchAllDevices() async {
    final response = await http.get(
      Uri.parse('$baseUrl/merak'),
      headers: {
        'Authorization': 'Bearer $_authToken',
        'Content-Type': 'application/json'
      },
    );

    if (response.statusCode == 200) {
      List jsonResponse = json.decode(response.body);
      return jsonResponse.map((device) => MerakDevice.fromJson(device)).toList();
    } else {
      throw Exception('Failed to load all devices');
    }
  }

  // Fetch Device Data for Specific Minutes (requires authentication)
  Future<List<MerakDevice>> fetchDevicesForMinutes(int minutes) async {
    final response = await http.get(
      Uri.parse('$baseUrl/merak/minuty/$minutes'),
      headers: {
        'Authorization': 'Bearer $_authToken',
        'Content-Type': 'application/json'
      },
    );

    if (response.statusCode == 200) {
      List jsonResponse = json.decode(response.body);
      return jsonResponse.map((device) => MerakDevice.fromJson(device)).toList();
    } else {
      throw Exception(json.decode(response.body)['error'] ?? 'Failed to load devices');
    }
  }

  // Alarm State
  Future<AlarmState> fetchAlarmState(int deviceId) async {
    final response = await http.get(Uri.parse('$baseUrl/merak/alarm/stav/$deviceId'));

    if (response.statusCode == 200) {
      int code = json.decode(response.body);
      return AlarmState.fromCode(code);
    } else {
      throw Exception(json.decode(response.body)['error'] ?? 'Failed to fetch alarm state');
    }
  }

  // Aggregation Methods
  Future<AgregaceData> fetchAggregationForPeriod(String period) async {
    final periodMap = {
      'den': 'agregaceDen',
      'tyden': 'agregaceTyden',
      'mesic': 'agregaceMesic',
      'rok': 'agregaceRok'
    };

    if (!periodMap.containsKey(period)) {
      throw Exception('Invalid aggregation period');
    }

    final response = await http.get(
      Uri.parse('$baseUrl/merak/${periodMap[period]}'),
      headers: {
        'Authorization': 'Bearer $_authToken',
        'Content-Type': 'application/json'
      },
    );

    if (response.statusCode == 200) {
      return AgregaceData.fromJson(json.decode(response.body));
    } else {
      throw Exception(json.decode(response.body)['error'] ?? 'Failed to fetch aggregation');
    }
  }

  // Add these methods to your existing ApiService class

// Add an alarm for a specific device
  Future<void> addAlarm(int deviceId, int alarmCode) async {
    try {
      if (_authToken == null) {
        throw Exception('Authentication token is null');
      }

      final response = await http.get(
        Uri.parse('$baseUrl/admin/alarm/pridat/$deviceId/$alarmCode'),
        headers: {
          'Authorization': 'Bearer $_authToken',
          'Content-Type': 'application/json'
        },
      );

      print('Response status code: ${response.statusCode}');
      print('Response body: ${response.body}');

      if (response.statusCode != 200) {
        throw Exception(json.decode(response.body)['error'] ?? 'Failed to add alarm');
      }
    } catch (e) {
      print('Detailed error: $e');
      rethrow;
    }
  }

// Remove an alarm for a specific device
  Future<void> removeAlarm(int deviceId) async {
    final response = await http.get(
      Uri.parse('$baseUrl/admin/alarm/odstranit/$deviceId'),
      headers: {
        'Authorization': 'Bearer $_authToken',
        'Content-Type': 'application/json'
      },
    );

    if (response.statusCode != 200) {
      throw Exception(json.decode(response.body)['error'] ?? 'Failed to remove alarm');
    }
  }
}