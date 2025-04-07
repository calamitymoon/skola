import 'package:flutter/material.dart';
import '../services/api_service.dart';
import '../models/measuring_device.dart';

class DevicesScreen extends StatefulWidget {
  @override
  _DevicesScreenState createState() => _DevicesScreenState();
}

class _DevicesScreenState extends State<DevicesScreen> {
  late Future<List<MerakDevice>> _limitedDevices;
  final ApiService _apiService = ApiService();

  @override
  void initState() {
    super.initState();
    _limitedDevices = _apiService.fetchLimitedDevices();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Měřicí přístroje'),
      ),
      body: FutureBuilder<List<MerakDevice>>(
        future: _limitedDevices,
        builder: (context, snapshot) {
          if (snapshot.connectionState == ConnectionState.waiting) {
            return Center(child: CircularProgressIndicator());
          } else if (snapshot.hasError) {
            return Center(child: Text('Chyba: ${snapshot.error}'));
          } else if (!snapshot.hasData || snapshot.data!.isEmpty) {
            return Center(child: Text('Žádná data'));
          }

          return ListView.builder(
            itemCount: snapshot.data!.length,
            itemBuilder: (context, index) {
              final device = snapshot.data![index];
              return ListTile(
                title: Text('Přístroj ${device.id_pristroje}'),
                subtitle: Column(
                  crossAxisAlignment: CrossAxisAlignment.start,
                  children: [
                    Text('Teplota: ${device.teplota}'),
                    Text('Vlhkost: ${device.vlhkost}'),
                    Text('CO2: ${device.co2}'),
                    Text('Tlak: ${device.tlak}'),
                  ],
                ),
              );
            },
          );
        },
      ),
    );
  }
}