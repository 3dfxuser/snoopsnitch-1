package de.srlabs.msd.upload;

import java.sql.Timestamp;
import java.util.Vector;

import android.content.ContentValues;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.util.Log;
import de.srlabs.msd.util.Utils;

/**
 * This class provides some manual object relational mapping to entries of the database table files.
 *
 */
public class DumpFile {
	private long id = -1;
	private String filename;
	private long start_time;
	private long end_time;
	private int file_type;
	public static final int TYPE_DEBUG_LOG = 1;
	public static final int TYPE_ENCRYPTED_QDMON = 2;
	private boolean sms;
	private boolean imsi_catcher;
	private int state;
	public static final int STATE_RECORDING = 1;
	public static final int STATE_AVAILABLE = 2;
	public static final int STATE_PENDING = 3;
	public static final int STATE_UPLOADED = 4;
	public static final int STATE_DELETED = 5;
	public static final int STATE_RECORDING_PENDING = 6;
	
	public DumpFile(String filename, int type) {
		this.filename = filename;
		this.file_type = type;
		this.state = STATE_RECORDING;
		this.start_time = System.currentTimeMillis();
		this.end_time = System.currentTimeMillis();
	}

	public DumpFile(Cursor c) {
		id = c.getLong(c.getColumnIndex("_id"));
		filename = c.getString(c.getColumnIndex("filename"));
		start_time = Timestamp.valueOf(c.getString(c.getColumnIndex("start_time"))).getTime();
		end_time = Timestamp.valueOf(c.getString(c.getColumnIndex("end_time"))).getTime();
		file_type = c.getInt(c.getColumnIndex("file_type"));
		sms = c.getInt(c.getColumnIndex("sms")) != 0;
		imsi_catcher = c.getInt(c.getColumnIndex("imsi_catcher")) != 0;
		state = c.getInt(c.getColumnIndex("state"));
	}

	/**
	 * Gets all files between time1 and time2 from the database. time2 can be null to get only files containing time1.
	 * @param db An SQLiteDatabase object to get the files from
	 * @param type Optional, get files of a specific type only
	 * @param time1 Start time
	 * @param time2 End time
	 * @param rangeSeconds Extend the range from time1 to time2 by rangeSeconds seconds to get the surrounding dumps as well
	 * @return
	 */
	public static Vector<DumpFile> getFiles(SQLiteDatabase db, Integer type, long time1, Long time2, Integer rangeSeconds){
		if(time2 == null)
			time2 = time1;
		if(time2 < time1){
			long tmp = time1;
			time1 = time2;
			time2 = tmp;
		}
		if(rangeSeconds != null){
			time1 -= rangeSeconds * 1000L;
			time2 += rangeSeconds * 1000L;
		}
		String selection = "end_time >= '" + (new Timestamp(time1)).toString() + "' AND start_time <= '" + (new Timestamp(time1)).toString() + "'";
		if(type != null)
			selection += " AND file_type = " + type;
		return getFiles(db, selection);
	}
	public static Vector<DumpFile> getFiles(SQLiteDatabase db, String selection){
		Vector<DumpFile> result = new Vector<DumpFile>();
		Cursor c = db.query("files", null, selection, null, null, null, "_id");
		while(c.moveToNext()){
			DumpFile entry = new DumpFile(c);
			result.add(entry);
		}
		return result;
	}
	@Override
	public String toString() {
		StringBuffer result = new StringBuffer("DumpFile ID=" + id + "  filename=" + filename);
		result.append("  start=" + Utils.formatTimestamp(start_time) + "  end=" + Utils.formatTimestamp(end_time));
		result.append("  file_type=" + typeToString(file_type));
		result.append("  state=" + stateToString(state));
		result.append("  sms=" + sms + "  imsi_catcher=" + imsi_catcher);
		return result.toString();
	}
	public static String typeToString(int type){
		if(type == TYPE_DEBUG_LOG)
			return "Debug log";
		else if(type == TYPE_ENCRYPTED_QDMON)
			return "Encrypted qdmon dump";
		else
			return "Invalid Dumpfile type " + type;
	}
	public static String stateToString(int state){
		if(state == STATE_RECORDING)
			return "Recording";
		else if(state == STATE_AVAILABLE)
			return "Available";
		else if(state == STATE_PENDING)
			return "Pending for upload";
		else if(state == STATE_UPLOADED)
			return "Uploaded";
		else if(state == STATE_DELETED)
			return "Deleted";
		else if(state == STATE_RECORDING_PENDING)
			return "Recording and pending for upload";
		else
			return "Invalid state " + state;
	}
	public void recordingStopped(){
		if(state == STATE_RECORDING){
			state = STATE_AVAILABLE;
		} else if(state == STATE_RECORDING_PENDING){
			state = STATE_PENDING;
		} else{
			throw new IllegalStateException("recordingSopped can only be called in STATE_RECORDING and STATE_RECORDING_PENDING. Current State: " + stateToString(state) + " (" + state + ")");
		}
		end_time = System.currentTimeMillis();
	}
	/**
	 * Inserts this object to the database
	 * @param db
	 */
	public void insert(SQLiteDatabase db){
		if(id != -1)
			throw new IllegalStateException("Dumpfile " + filename + " already exists in database, please use update() instead of insert()");
		ContentValues values = this.makeContentValues();
		id = db.insert("files",null,values);
		if( id == -1)
			throw new IllegalStateException("Failed to insert file " + filename + " into database");
	}
	private ContentValues makeContentValues() {
		ContentValues result = new ContentValues();
		result.put("filename",filename);
		result.put("start_time", (new Timestamp(start_time)).toString());
		result.put("end_time", (new Timestamp(end_time)).toString());
		result.put("file_type",file_type);
		result.put("sms",sms ? 1:0);
		result.put("imsi_catcher",imsi_catcher ? 1:0);
		result.put("state", state);
		return result;
	}
//	TODO
//	/**
//	 * Updates an existing object (identified by the id field) in the database
//	 * @param db
//	 */
//	public void update(SQLiteDatabase db){
//		ContentValues values = this.makeContentValues();
//		int numRows = db.update("files", values, "_id = " + id, null);
//		if(numRows != 1)
//			throw new IllegalStateException("Update statement failed, id " + id + " in table files not found");
//	}
	public long getEnd_time() {
		return end_time;
	}

	public void setEnd_time(long end_time) {
		this.end_time = end_time;
	}

	public boolean isSms() {
		return sms;
	}

	public void setSms(boolean sms) {
		this.sms = sms;
	}

	public boolean isImsi_catcher() {
		return imsi_catcher;
	}

	public void setImsi_catcher(boolean imsi_catcher) {
		this.imsi_catcher = imsi_catcher;
	}

	public long getId() {
		return id;
	}

	public String getFilename() {
		return filename;
	}

	public long getStart_time() {
		return start_time;
	}

	public int getFile_type() {
		return file_type;
	}

	public int getState() {
		return state;
	}

	public void endRecording(SQLiteDatabase db){
		this.end_time = System.currentTimeMillis();
		ContentValues values = new ContentValues();
		values.put("end_time", (new Timestamp(end_time)).toString());
		if(state == STATE_RECORDING){
			if(updateState(db, STATE_RECORDING, STATE_AVAILABLE, values))
				return;
		}
		if(updateState(db, STATE_RECORDING_PENDING, STATE_PENDING, values))
			return;
		throw new IllegalStateException("Can't change state of file " + getFilename() + " id=" + getId());
	}
	public void markForUpload(SQLiteDatabase db) {
		Log.i("DumpFile", "markForUpload: " + this);
		if(state == STATE_AVAILABLE){
			if(updateState(db, STATE_AVAILABLE, STATE_PENDING, null))
				return;
		} else if(state == STATE_RECORDING){
			if(updateState(db, STATE_RECORDING, STATE_RECORDING_PENDING, null))
				return;
			// Fallback in case the database row has been changed from RECORDING
			// to AVAILABLE by MsdService since it has been read from the
			// database.
			if(updateState(db, STATE_AVAILABLE, STATE_PENDING, null))
				return;
		}
		Log.e("DumpFile", "markForUpload failed: " + this);
	}

	/**
	 * Updates the state field from oldState to newState
	 * @param db
	 * @param oldState
	 * @param newState
	 * @param values Some extra values to change in the database
	 * @return
	 */
	public boolean updateState(SQLiteDatabase db, int oldState, int newState, ContentValues values) {
		if(values == null)
			values = new ContentValues();
		values.put("state", newState);
		int numModified = db.update("files", values, "_id = " + id + " AND state = " + oldState, null);
		return numModified == 1;
	}

	public boolean updateSms(SQLiteDatabase db, boolean b) {
		ContentValues values = new ContentValues();
		values.put("sms", b?1:0);
		int numModified = db.update("files", values, "_id = " + id, null);
		return numModified == 1;
	}

	public boolean updateImsi(SQLiteDatabase db, boolean b) {
		ContentValues values = new ContentValues();
		values.put("imsi_catcher", b?1:0);
		int numModified = db.update("files", values, "_id = " + id, null);
		return numModified == 1;
	}
	
}